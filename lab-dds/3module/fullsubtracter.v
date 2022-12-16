// full subtracter
module fullsub(
    output s, c_out,
    input a, b, c_in
);
assign s = a^b^c_in;
assign c_out = (~a)&b | c_in&(~a | b);
endmodule

// testbench
module fullsub_tb;
reg a, b, c_in;
wire s, c_out;

fullsub mymodel(s, c_out, a, b, c_in);
initial begin
    $display("full subtracter using behavioral level model.");
    $display("a b c_in\tdiff borrow");
    $monitor("%b %b %b\t\t%b\t%b", a, b, c_in, s, c_out);
        for (integer i = 0; i < 8; i++) begin
            {a, b, c_in} = i;   #5;
        end

end
endmodule