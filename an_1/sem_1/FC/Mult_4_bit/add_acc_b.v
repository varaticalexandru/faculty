module add_acc_b(
  input en,
  input start, 
  input clk, 
  input [4:0]acc, b,
  output reg [4:0]s
);

wire [4:0] temp_s;

special_five_bit_FAC add(
  .A(acc),
  .B(b), 
  .S(temp_s) 
);

always @(posedge clk) begin 
  $display("ac=%b b=%b",acc,b);
  if (~start) begin
    if (en) s = temp_s; 
    else s = acc;
  end
  else
    s = acc;
end 
endmodule

