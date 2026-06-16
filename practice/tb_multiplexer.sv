module tb_multiplexer;

logic s;
logic i0;
logic i1;
logic y;

multiplexer uut (
    .i0(i0),
    .i1(i1),
    .s(s),
    .y(y)
    );
initial begin
    $dumpfile("multiplexer.vcd");
    $dumpvars(0, tb_multiplexer);

    i0 = 0; i1 = 1; s = 0;
    #10;

    i0 = 0; i1 = 1; s = 1;
    #10;

    i0 = 1; i1 = 0; s = 0;
    #10;

    i0 = 1; i1 = 0; s = 1;
    #10;

    $finish;
end
endmodule
