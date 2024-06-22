
module SUB_CPU (
	clock_bridge_0_in_clk_clk,
	reset_bridge_0_in_reset_reset,
	mm_bridge_0_m0_waitrequest,
	mm_bridge_0_m0_readdata,
	mm_bridge_0_m0_readdatavalid,
	mm_bridge_0_m0_burstcount,
	mm_bridge_0_m0_writedata,
	mm_bridge_0_m0_address,
	mm_bridge_0_m0_write,
	mm_bridge_0_m0_read,
	mm_bridge_0_m0_byteenable,
	mm_bridge_0_m0_debugaccess);	

	input		clock_bridge_0_in_clk_clk;
	input		reset_bridge_0_in_reset_reset;
	input		mm_bridge_0_m0_waitrequest;
	input	[31:0]	mm_bridge_0_m0_readdata;
	input		mm_bridge_0_m0_readdatavalid;
	output	[0:0]	mm_bridge_0_m0_burstcount;
	output	[31:0]	mm_bridge_0_m0_writedata;
	output	[9:0]	mm_bridge_0_m0_address;
	output		mm_bridge_0_m0_write;
	output		mm_bridge_0_m0_read;
	output	[3:0]	mm_bridge_0_m0_byteenable;
	output		mm_bridge_0_m0_debugaccess;
endmodule
