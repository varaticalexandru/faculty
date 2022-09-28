// D flip-flop for 5 bits(without reset)
module reg_5_bit(
  input [4:0]a, 
  input start,
  input clk,
  output reg [4:0]ac
);
initial begin
ac=0;
end
always @(posedge clk) begin 
  if (start) ac = a;
  $display("ac=%b",ac);
end
endmodule


