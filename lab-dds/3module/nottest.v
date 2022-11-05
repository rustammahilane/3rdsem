module not_tb;
	reg a;
	wire y;

not_ test(a,y);
initial
	begin
	$monitor("%b %b", a, y);
	$dumpfile("nottest.vcd");
    $dumpvars();
	a = 0; #5;
	a = 1; #5;
	end
endmodule
