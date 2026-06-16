module tb_xor4();
	logic [3:0] a;
    logic y, yexpected;
    logic clk, reset;
	logic [31:0] vectornum, errors;
	logic [4:0] testvectors[10000:0];
	
	// instantiate device under test
	xor4 dut(a, y);
	
	// generate clock
	always
		begin
			clk = 1; #5; clk = 0; #5;
		end
	
	// at start of test, load vectors
	// and pulse reset
	initial
		begin
            $dumpfile("xor4.vcd");
            $dumpvars(0, tb_xor4);

			$readmemb("xor4tb.txt", testvectors);
			vectornum = 0; errors = 0;
			reset = 1; #22; reset = 0;
		end
		
	// apply test vectors on rising edge of clk
	always @(posedge clk)
		begin
			#1; {a, yexpected} = testvectors[vectornum];
		end
		
	// check results on falling edge of clk
	always @(negedge clk)
		if (~reset) begin // skip during reset
			if (y !== yexpected) begin // check result
				$display("Error inputs = %b", a);
				$display(" outputs = %b (%b expected)", y, 
                         yexpected);
				errors = errors + 1;
			end
			vectornum = vectornum + 1;
            if (vectornum == 16) begin
				$display("%d tests completed with %d errors",
				         vectornum, errors);
            $finish;
	    	end
		end
endmodule
