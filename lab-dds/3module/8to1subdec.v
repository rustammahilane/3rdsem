module decod(
    input a,b,c,
    output y0,y1,y2,y3,y4,y5,y6,y7,
    output d,borrow
);
assign y0 = ~a & ~b & ~c;
assign y1 = ~a & ~b & c;
assign y2 = ~a & b & ~c;
assign y3 = ~a & b & c;
assign y4 = a & ~b & ~c;
assign y5 = a & ~b & c;
assign y6 = a & b & ~c;
assign y7 = a & b & c;
assign d = y1 | y2 | y4 | y7;
assign borrow = y1|y2|y3|y7;
endmodule

//testbench
module test;
reg a, b, c_in;
wire y0,y1,y2,y3,y4,y5,y6,y7;
wire d, borrow;

decod mymodel(a,b,c_in,y0,y1,y2,y3,y4,y5,y6,y7,d,borrow);
initial begin
    $display("Full Subtracter using 8:1 decoder\n");
    $monitor("%b %b %b  diff: %b  borrow: %b", a, b, c_in, d, borrow);
    a=0; b=0; c_in=0; #5;
	a=0; b=0; c_in=1; #5;
	a=0; b=1; c_in=0; #5;
	a=0; b=1; c_in=1; #5;
	a=1; b=0; c_in=0; #5;
	a=1; b=0; c_in=1; #5;
	a=1; b=1; c_in=0; #5;
	a=1; b=1; c_in=1; #5;
end
endmodule