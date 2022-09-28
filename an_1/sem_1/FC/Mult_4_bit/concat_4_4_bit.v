module concat_4_4_bit (
                        input start,
                        input [3:0] a,q,
                        input clk,
                        output reg [7:0] p,
                        output reg stop
                      );
  
  always @(posedge clk) begin
    if (~start) begin
      p = {a, q};
      stop = 1'b1;
    end
  end

endmodule
