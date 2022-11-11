module nand_to_other(
    output a_not,b_not,ab_or,ab_and,ab_nand,ab_nor,
    input a,b
);
nand(a_not,a,a);
nand(b_not,b,b);
nand(ab_or,a_not,b_not);
nand(ab_nand,a,b);
nand(ab_and, ab_nand,ab_nand);
nand(ab_nor,ab_or,ab_or);
endmodule
