
module mux(
    input y0,y1,y2,y3,y4,y5,y6,y7,a,b,c,
    output out
);
assign y0 = ~a & ~b & ~c;
assign y1 = ~a & ~b & c;
assign y2 = ~a & b & ~c;
assign y3 = ~a & b & c;
assign y4 = a & ~b & ~c;
assign y5 = a & ~b & c;
assign y6 = a & b & ~c;
assign y7 = a & b & c;
assign out = y0|y1|y2|y3|y4|y5|y6|y7;
endmodule

//testbench
module test;
reg a,b,c;
wire s,d;

mux sum(0,1,1,0,1,0,0,1,a,b,c,s);
mux carry(0,1,1,1,0,0,0,1,a,b,c,d);
initial begin
    $display("full subtracter using 8:1 mux");
    $monitor("%b %b %b   %b %b",a,b,c,s,d);
    a=0; b=0; c=0; #5;
	a=0; b=0; c=1; #5;
	a=0; b=1; c=0; #5;
	a=0; b=1; c=1; #5;
	a=1; b=0; c=0; #5;
	a=1; b=0; c=1; #5;
	a=1; b=1; c=0; #5;
	a=1; b=1; c=1; #5;
end
endmodule
