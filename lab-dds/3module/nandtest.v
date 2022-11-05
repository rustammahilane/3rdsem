
module nand_tb;
       reg a; reg b;
       wire y;

nand_ test(a,b,y);
initial
        begin
        $monitor("%b%b %b", a,b,y);
        $dumpfile("nandtest.vcd");
        $dumpvars();
        a = 0; b = 0; #5;
        a = 0; b = 1; #5;
        a = 1; b = 0; #5;
        a = 1; b = 1; #5;
        end
endmodule
