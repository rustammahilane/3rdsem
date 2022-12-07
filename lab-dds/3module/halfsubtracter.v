// halfadder
module halfsub(
    output s, c_out,
    input a, b
);
xor(s, a, b);
and(c_out, ~a, b);
endmodule

// testbench
module halfsub_tb;
reg a, b;
wire s, c_out;

halfsub mymodel(s, c_out, a, b);
initial begin
    $display("half subtracter using gate level modelling.");
    $monitor("ab=%b%b\tdiff=%b\tborrow=%b", a, b, s, c_out);
    $dumpfile("halfsubtracter.vcd");
    $dumpvars();
        for (integer i = 0; i <= 3; i++) begin
            {a, b} = i; #5;
        end
end
endmodule