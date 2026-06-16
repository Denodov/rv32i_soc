module multiplexer(
    input logic s,
    input logic i0,
    input logic i1,
    output logic y
    );

    assign y = s ? i1 : i0;

    endmodule
