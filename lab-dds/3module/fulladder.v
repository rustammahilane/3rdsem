// fulladder
module fulladder(
    output s, c_out,
    input a, b, c_in
);
assign s = a^b^c_in;
assign c_out = (b&c_in) | (a&b) | (b&c_in);
endmodule

// testbench
module fulladder_tb;
reg a, b, c_in;
wire s, c_out;

fulladder mymodel(s, c_out, a, b, c_in);
initial begin
    $display("full adder using behavioral level model.");
    $display("a b c_in\ts c_out");
    $monitor("%b %b %b\t\t%b %b", a, b, c_in, s, c_out);
        for (integer i = 0; i < 8; i++) begin
            {a, b, c_in} = i;   #5;
        end

end
endmodule