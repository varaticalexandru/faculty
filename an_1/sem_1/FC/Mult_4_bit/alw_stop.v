module alw_stop(
      input  clk,
      output reg stop
    );
  
always @(posedge clk) begin
  stop = 1'b0;
end
endmodule