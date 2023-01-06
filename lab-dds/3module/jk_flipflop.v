module flipflop(
    input j,k,clk,
    output reg q
);
always @(posedge clk)
case({j,k})
    2'b00:  q <= q; 
    2'b01:  q <= 0;
    2'b10:  q <= 1; 
    2'b11:  q <= ~q; 
endcase
endmodule

//testbench
module main;
reg j ,k,clk=0;
wire q;
flipflop my(j,k,clk,q);
always begin
    clk = ~clk; #5;
end
initial begin
$monitor("J,K: %b%b  Q: %b",j,k,q);
    $dumpfile("jk_ff.vcd");
    $dumpvars();
    j = 0; k = 0; #10;
	j = 0; k = 1; #10;
    j = 0; k = 0; #10;
	j = 1; k = 0; #10;
    j = 0; k = 0; #10;
	j = 1; k = 1; #10;
    $finish;
end
endmodule