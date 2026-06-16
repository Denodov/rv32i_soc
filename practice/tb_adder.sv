module tb_adder;

logic [3:0] a;
logic [3:0] b;
logic [3:0] sum;

adder uut (
    .a(a),
    .b(b),
    .sum(sum)
);

initial begin

    $dumpfile("adder.vcd");
    $dumpvars(0, tb_adder);

    a = 4'd3; // 4-bit decimal 3
    b = 4'd2;
    #10;

    a = 4'd7;
    b = 4'd1;
    #10;

    a = 4'd4;
    b = 4'd5;
    #10;

    $finish;
end

endmodule
