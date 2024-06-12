// (C) 2001-2013 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.


// (C) 2001-2013 Altera Corporation. All rights reserved.
// Your use of Altera Corporation's design tools, logic functions and other 
// software and tools, and its AMPP partner logic functions, and any output 
// files any of the foregoing (including device programming or simulation 
// files), and any associated documentation or information are expressly subject 
// to the terms and conditions of the Altera Program License Subscription 
// Agreement, Altera MegaCore Function License Agreement, or other applicable 
// license agreement, including, without limitation, that your use is for the 
// sole purpose of programming logic devices manufactured by Altera and sold by 
// Altera or its authorized distributors.  Please refer to the applicable 
// agreement for further details.


// $Id: //acds/rel/13.1/ip/merlin/altera_merlin_router/altera_merlin_router.sv.terp#5 $
// $Revision: #5 $
// $Date: 2013/09/30 $
// $Author: perforce $

// -------------------------------------------------------
// Merlin Router
//
// Asserts the appropriate one-hot encoded channel based on 
// either (a) the address or (b) the dest id. The DECODER_TYPE
// parameter controls this behaviour. 0 means address decoder,
// 1 means dest id decoder.
//
// In the case of (a), it also sets the destination id.
// -------------------------------------------------------

`timescale 1 ns / 1 ns

module Mega_JSoC_mm_interconnect_0_addr_router_001_default_decode
  #(
     parameter DEFAULT_CHANNEL = 1,
               DEFAULT_WR_CHANNEL = -1,
               DEFAULT_RD_CHANNEL = -1,
               DEFAULT_DESTID = 48 
   )
  (output [96 - 91 : 0] default_destination_id,
   output [61-1 : 0] default_wr_channel,
   output [61-1 : 0] default_rd_channel,
   output [61-1 : 0] default_src_channel
  );

  assign default_destination_id = 
    DEFAULT_DESTID[96 - 91 : 0];

  generate begin : default_decode
    if (DEFAULT_CHANNEL == -1) begin
      assign default_src_channel = '0;
    end
    else begin
      assign default_src_channel = 61'b1 << DEFAULT_CHANNEL;
    end
  end
  endgenerate

  generate begin : default_decode_rw
    if (DEFAULT_RD_CHANNEL == -1) begin
      assign default_wr_channel = '0;
      assign default_rd_channel = '0;
    end
    else begin
      assign default_wr_channel = 61'b1 << DEFAULT_WR_CHANNEL;
      assign default_rd_channel = 61'b1 << DEFAULT_RD_CHANNEL;
    end
  end
  endgenerate

endmodule


module Mega_JSoC_mm_interconnect_0_addr_router_001
(
    // -------------------
    // Clock & Reset
    // -------------------
    input clk,
    input reset,

    // -------------------
    // Command Sink (Input)
    // -------------------
    input                       sink_valid,
    input  [110-1 : 0]    sink_data,
    input                       sink_startofpacket,
    input                       sink_endofpacket,
    output                      sink_ready,

    // -------------------
    // Command Source (Output)
    // -------------------
    output                          src_valid,
    output reg [110-1    : 0] src_data,
    output reg [61-1 : 0] src_channel,
    output                          src_startofpacket,
    output                          src_endofpacket,
    input                           src_ready
);

    // -------------------------------------------------------
    // Local parameters and variables
    // -------------------------------------------------------
    localparam PKT_ADDR_H = 63;
    localparam PKT_ADDR_L = 36;
    localparam PKT_DEST_ID_H = 96;
    localparam PKT_DEST_ID_L = 91;
    localparam PKT_PROTECTION_H = 100;
    localparam PKT_PROTECTION_L = 98;
    localparam ST_DATA_W = 110;
    localparam ST_CHANNEL_W = 61;
    localparam DECODER_TYPE = 0;

    localparam PKT_TRANS_WRITE = 66;
    localparam PKT_TRANS_READ  = 67;

    localparam PKT_ADDR_W = PKT_ADDR_H-PKT_ADDR_L + 1;
    localparam PKT_DEST_ID_W = PKT_DEST_ID_H-PKT_DEST_ID_L + 1;



    // -------------------------------------------------------
    // Figure out the number of bits to mask off for each slave span
    // during address decoding
    // -------------------------------------------------------
    localparam PAD0 = log2ceil(64'h8000000 - 64'h0); 
    localparam PAD1 = log2ceil(64'h8001000 - 64'h8000800); 
    localparam PAD2 = log2ceil(64'h8001020 - 64'h8001000); 
    localparam PAD3 = log2ceil(64'h8001040 - 64'h8001020); 
    localparam PAD4 = log2ceil(64'h8001060 - 64'h8001040); 
    localparam PAD5 = log2ceil(64'h8001080 - 64'h8001060); 
    localparam PAD6 = log2ceil(64'h80010a0 - 64'h8001080); 
    localparam PAD7 = log2ceil(64'h80010c0 - 64'h80010a0); 
    localparam PAD8 = log2ceil(64'h80010e0 - 64'h80010c0); 
    localparam PAD9 = log2ceil(64'h80010f0 - 64'h80010e0); 
    localparam PAD10 = log2ceil(64'h80010f8 - 64'h80010f0); 
    localparam PAD11 = log2ceil(64'h8001100 - 64'h80010f8); 
    localparam PAD12 = log2ceil(64'h8001104 - 64'h8001100); 
    localparam PAD13 = log2ceil(64'h8001108 - 64'h8001104); 
    localparam PAD14 = log2ceil(64'h800110c - 64'h8001108); 
    localparam PAD15 = log2ceil(64'h8001110 - 64'h800110c); 
    localparam PAD16 = log2ceil(64'h8001114 - 64'h8001110); 
    localparam PAD17 = log2ceil(64'h8001118 - 64'h8001114); 
    // -------------------------------------------------------
    // Work out which address bits are significant based on the
    // address range of the slaves. If the required width is too
    // large or too small, we use the address field width instead.
    // -------------------------------------------------------
    localparam ADDR_RANGE = 64'h8001118;
    localparam RANGE_ADDR_WIDTH = log2ceil(ADDR_RANGE);
    localparam OPTIMIZED_ADDR_H = (RANGE_ADDR_WIDTH > PKT_ADDR_W) ||
                                  (RANGE_ADDR_WIDTH == 0) ?
                                        PKT_ADDR_H :
                                        PKT_ADDR_L + RANGE_ADDR_WIDTH - 1;

    localparam RG = RANGE_ADDR_WIDTH-1;
    localparam REAL_ADDRESS_RANGE = OPTIMIZED_ADDR_H - PKT_ADDR_L;

      reg [PKT_ADDR_W-1 : 0] address;
      always @* begin
        address = {PKT_ADDR_W{1'b0}};
        address [REAL_ADDRESS_RANGE:0] = sink_data[OPTIMIZED_ADDR_H : PKT_ADDR_L];
      end   

    // -------------------------------------------------------
    // Pass almost everything through, untouched
    // -------------------------------------------------------
    assign sink_ready        = src_ready;
    assign src_valid         = sink_valid;
    assign src_startofpacket = sink_startofpacket;
    assign src_endofpacket   = sink_endofpacket;
    wire [PKT_DEST_ID_W-1:0] default_destid;
    wire [61-1 : 0] default_src_channel;




    // -------------------------------------------------------
    // Write and read transaction signals
    // -------------------------------------------------------
    wire write_transaction;
    assign write_transaction = sink_data[PKT_TRANS_WRITE];
    wire read_transaction;
    assign read_transaction  = sink_data[PKT_TRANS_READ];


    Mega_JSoC_mm_interconnect_0_addr_router_001_default_decode the_default_decode(
      .default_destination_id (default_destid),
      .default_wr_channel   (),
      .default_rd_channel   (),
      .default_src_channel  (default_src_channel)
    );

    always @* begin
        src_data    = sink_data;
        src_channel = default_src_channel;
        src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = default_destid;

        // --------------------------------------------------
        // Address Decoder
        // Sets the channel and destination ID based on the address
        // --------------------------------------------------

    // ( 0x0 .. 0x8000000 )
    if ( {address[RG:PAD0],{PAD0{1'b0}}} == 28'h0   ) begin
            src_channel = 61'b000000000000000010;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 48;
    end

    // ( 0x8000800 .. 0x8001000 )
    if ( {address[RG:PAD1],{PAD1{1'b0}}} == 28'h8000800   ) begin
            src_channel = 61'b000000000000000001;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 5;
    end

    // ( 0x8001000 .. 0x8001020 )
    if ( {address[RG:PAD2],{PAD2{1'b0}}} == 28'h8001000   ) begin
            src_channel = 61'b100000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 33;
    end

    // ( 0x8001020 .. 0x8001040 )
    if ( {address[RG:PAD3],{PAD3{1'b0}}} == 28'h8001020   ) begin
            src_channel = 61'b001000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 30;
    end

    // ( 0x8001040 .. 0x8001060 )
    if ( {address[RG:PAD4],{PAD4{1'b0}}} == 28'h8001040   ) begin
            src_channel = 61'b000010000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 27;
    end

    // ( 0x8001060 .. 0x8001080 )
    if ( {address[RG:PAD5],{PAD5{1'b0}}} == 28'h8001060   ) begin
            src_channel = 61'b000000100000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 24;
    end

    // ( 0x8001080 .. 0x80010a0 )
    if ( {address[RG:PAD6],{PAD6{1'b0}}} == 28'h8001080   ) begin
            src_channel = 61'b000000001000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 21;
    end

    // ( 0x80010a0 .. 0x80010c0 )
    if ( {address[RG:PAD7],{PAD7{1'b0}}} == 28'h80010a0   ) begin
            src_channel = 61'b000000000010000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 18;
    end

    // ( 0x80010c0 .. 0x80010e0 )
    if ( {address[RG:PAD8],{PAD8{1'b0}}} == 28'h80010c0   ) begin
            src_channel = 61'b000000000000001000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 60;
    end

    // ( 0x80010e0 .. 0x80010f0 )
    if ( {address[RG:PAD9],{PAD9{1'b0}}} == 28'h80010e0   ) begin
            src_channel = 61'b000000000000100000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 47;
    end

    // ( 0x80010f0 .. 0x80010f8 )
    if ( {address[RG:PAD10],{PAD10{1'b0}}} == 28'h80010f0  && read_transaction  ) begin
            src_channel = 61'b000000000000010000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 49;
    end

    // ( 0x80010f8 .. 0x8001100 )
    if ( {address[RG:PAD11],{PAD11{1'b0}}} == 28'h80010f8   ) begin
            src_channel = 61'b000000000000000100;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 41;
    end

    // ( 0x8001100 .. 0x8001104 )
    if ( {address[RG:PAD12],{PAD12{1'b0}}} == 28'h8001100  && write_transaction  ) begin
            src_channel = 61'b010000000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 34;
    end

    // ( 0x8001104 .. 0x8001108 )
    if ( {address[RG:PAD13],{PAD13{1'b0}}} == 28'h8001104  && write_transaction  ) begin
            src_channel = 61'b000100000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 31;
    end

    // ( 0x8001108 .. 0x800110c )
    if ( {address[RG:PAD14],{PAD14{1'b0}}} == 28'h8001108  && write_transaction  ) begin
            src_channel = 61'b000001000000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 28;
    end

    // ( 0x800110c .. 0x8001110 )
    if ( {address[RG:PAD15],{PAD15{1'b0}}} == 28'h800110c  && write_transaction  ) begin
            src_channel = 61'b000000010000000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 25;
    end

    // ( 0x8001110 .. 0x8001114 )
    if ( {address[RG:PAD16],{PAD16{1'b0}}} == 28'h8001110  && write_transaction  ) begin
            src_channel = 61'b000000000100000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 22;
    end

    // ( 0x8001114 .. 0x8001118 )
    if ( {address[RG:PAD17],{PAD17{1'b0}}} == 28'h8001114  && write_transaction  ) begin
            src_channel = 61'b000000000001000000;
            src_data[PKT_DEST_ID_H:PKT_DEST_ID_L] = 19;
    end

end


    // --------------------------------------------------
    // Ceil(log2()) function
    // --------------------------------------------------
    function integer log2ceil;
        input reg[65:0] val;
        reg [65:0] i;

        begin
            i = 1;
            log2ceil = 0;

            while (i < val) begin
                log2ceil = log2ceil + 1;
                i = i << 1;
            end
        end
    endfunction

endmodule


