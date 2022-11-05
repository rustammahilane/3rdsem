module nand_( 
	input a,b,
	output y
);
assign y = ~(a&b);
endmodule
