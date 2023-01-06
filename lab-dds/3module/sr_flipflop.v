module flipflop(
    input s,r,clk,
    output q, qnot
);
wire y,w;
and (y,clk,s);
and (w,clk,r);
nor(q,w,qnot);
nor(qnot,y,q);
endmodule

//testbench
`timescale 1ns/1ns
module main;
reg s ,r,clk=0;
wire q,qnot;
flipflop my(s,r,clk,q,qnot);
always begin
    clk = ~clk; #5;
end
initial begin
$monitor("S,R: %b%b  Q,Qnot: %b%b",s,r,q,qnot);
    $dumpfile("sr.vcd");
    $dumpvars();
    s = 0; r = 0; #10;
	s = 0; r = 1; #10;
	s = 1; r = 0; #10;
	s = 1; r = 1; #10;
    $finish;
end
endmodule