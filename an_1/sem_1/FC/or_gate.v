module or_gate(
                input in1, in2,
                output reg out
              );
  parameter delay = 0;
        
  always @(*) begin
    #delay;
    out = in1 | in2;
  end

endmodule
