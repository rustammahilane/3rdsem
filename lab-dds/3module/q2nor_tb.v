`include "q2nor.v"

module universalnor;
reg a,b;
wire a_not,b_not,ab_or,ab_and,ab_nor,ab_nand;

nor_to_other test(a_not,b_not,ab_or,ab_and,ab_nand,ab_nor,a,b);
initial begin
    $display("Other gates using NOR gate.");
    $monitor("ab: %b%b    a_not: %b    b_not: %b    and: %b    or: %b    nand:%b"
        ,a,b,a_not,b_not,ab_and,ab_or,ab_nand);
    $dumpfile("q2nor_tb.vcd");
	$dumpvars();
	a = 0; b = 0; #10;
	a = 0; b = 1; #10;
	a = 1; b = 0; #10;
	a = 1; b = 1; #10;
    $finish;
end
endmodule
