// halfadder
module halfadder(
    output s, c_out,
    input a, b
);
xor(s, a, b);
and(c_out, a, b);
endmodule

// testbench
module halfadder_tb;
reg a, b;
wire s, c_out;

halfadder mymodel(s, c_out, a, b);
initial begin
    $display("half adder using gate level modelling.");
    $monitor("ab=%b%b\ts=%b\tc_out=%b", a, b, s, c_out);
    $dumpfile("halfadder.vcd");
    $dumpvars();
        for (integer i = 0; i <= 3; i++) begin
            {a, b} = i; #5;
        end
end
endmodule