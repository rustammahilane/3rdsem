module decod(
    input a,b,c,
    output y0,y1,y2,y3,y4,y5,y6,y7,
    output s,carry
);
assign y0 = ~a & ~b & ~c;
assign y1 = ~a & ~b & c;
assign y2 = ~a & b & ~c;
assign y3 = ~a & b & c;
assign y4 = a & ~b & ~c;
assign y5 = a & ~b & c;
assign y6 = a & b & ~c;
assign y7 = a & b & c;
assign s = y1 | y2 | y4 | y7;
assign carry = y3|y5|y6|y7;
endmodule

//testbench
module test;
reg a, b, c_in;
wire y0,y1,y2,y3,y4,y5,y6,y7;
wire s, carry;

decod mymodel(a,b,c_in,y0,y1,y2,y3,y4,y5,y6,y7,s,carry);
initial begin
    $display("Full Adder using 8:1 decoder\n");
    $monitor("%b %b %b  sum: %b  carry: %b", a, b, c_in, s, carry);
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