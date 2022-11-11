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