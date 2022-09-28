// D flip-flop for 4 bits(without reset)
module reg_4_bit(
  input [3:0]x,
  input start,  
  input clk, 
  output reg [3:0]b
);
initial begin
b=0;
end
always @(posedge clk) begin 
  if(start) b = x;
  $display("reg_4_bit=%b",b);
end
endmodule

