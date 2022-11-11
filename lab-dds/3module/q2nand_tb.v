`include "q2nand.v"

module universalnand;
reg a,b;
wire a_not,b_not,ab_or,ab_and,ab_nand,ab_nor;

nand_to_other test(a_not,b_not,ab_or,ab_and,ab_nand,ab_nor,a,b);
initial begin
    $display("Other gates using NAND gate.");
    $monitor("ab: %b%b    a_not: %b    b_not: %b    or: %b    and: %b    nor:%b"
        ,a,b,a_not,b_not,ab_or,ab_and,ab_nor);
    $dumpfile("q2nand_tb.vcd");
	$dumpvars();
	a = 0; b = 0; #10;
	a = 0; b = 1; #10;
	a = 1; b = 0; #10;
	a = 1; b = 1; #10;
    $finish;
end
endmodule