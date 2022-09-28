module shift_reg(
                  input [4:0] A,
                  input [3:0] Q,
                  input clk,
                  output reg [4:0] A_out,
                  output reg [3:0] Q_out
                );
  
  reg [8:0] temp;
  
  always @(posedge clk) begin
    temp = {A, Q};
    temp = {1'b0, temp[8:1]};
    
    A_out = temp[8:4];
    Q_out = temp[3:0];
  end
  
endmodule