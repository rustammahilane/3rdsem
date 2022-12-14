module basic_gates(
    input a, b,
    output b_not_gate, and_gate, or_gate, 
            nand_gate, nor_gate, xor_gate, xnor_gate
);
assign b_not_gate = ~b;
assign and_gate = a&b;
assign or_gate = a|b;
assign nand_gate = ~(a&b);
assign nor_gate = ~(a|b);
assign xor_gate = a^b;
assign xnor_gate = ~(a^b);
endmodule

//testbench code
module basic_gates_tb;
reg a,b;
wire b_not_gate,and_gate,nand_gate,nor_gate,or_gate,xor_gate,xnor_gate;

basic_gates test(a,b,b_not_gate, and_gate, or_gate, 
            nand_gate, nor_gate, xor_gate, xnor_gate);

initial
begin
    $monitor("%b%b   b_not:%b    and:%b   or:%b   nand:%b    nor:%b   xor:%b   xnor:%b"
        ,a,b,b_not_gate,and_gate,or_gate,nand_gate,nor_gate,xor_gate,xnor_gate);
    $dumpfile("q1_tb.vcd");
	$dumpvars(0,basic_gates_tb);
	a = 0; b = 0; #10;
	a = 0; b = 1; #10;
	a = 1; b = 0; #10;
	a = 1; b = 1; #10;
    $finish;
end
endmodule