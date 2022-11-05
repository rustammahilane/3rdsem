module andtest;
	reg a; reg b;
	wire y;

and_ test(a,b,y);
initial
	begin
	$monitor("%b%b %b", a,b,y);
	$dumpfile("andtest.vcd");
	$dumpvars();
	a = 0; b = 0; #5;
	a = 0; b = 1; #5;
	a = 1; b = 0; #5;
	a = 1; b = 1; #5;
	end
endmodule
