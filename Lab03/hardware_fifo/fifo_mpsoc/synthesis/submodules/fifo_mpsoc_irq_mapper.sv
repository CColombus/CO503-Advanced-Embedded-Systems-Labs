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


// $Id: //acds/rel/13.1/ip/merlin/altera_irq_mapper/altera_irq_mapper.sv.terp#1 $
// $Revision: #1 $
// $Date: 2013/08/11 $
// $Author: swbranch $

// -------------------------------------------------------
// Altera IRQ Mapper
//
// Parameters
//   NUM_RCVRS        : 3
//   SENDER_IRW_WIDTH : 32
//   IRQ_MAP          : 0:1,1:16,2:20
//
// -------------------------------------------------------

`timescale 1 ns / 1 ns

module fifo_mpsoc_irq_mapper
(
    // -------------------
    // Clock & Reset
    // -------------------
    input clk,
    input reset,

    // -------------------
    // IRQ Receivers
    // -------------------
    input                receiver0_irq,
    input                receiver1_irq,
    input                receiver2_irq,

    // -------------------
    // Command Source (Output)
    // -------------------
    output reg [31 : 0] sender_irq
);


    always @* begin
	sender_irq = 0;

        sender_irq[1] = receiver0_irq;
        sender_irq[16] = receiver1_irq;
        sender_irq[20] = receiver2_irq;
    end

endmodule


