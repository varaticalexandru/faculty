module Add_BCD (
                  input [11:0] BCD_n1, 
                  input[7:0] BCD_n2,
                  output [11:0] BCD_out
                );
                  
initial begin
  BCD_out = {12{1'b0}};
end

always (*) begin
  for (i=0; i<3; i++) begin
    output[i] = BCD_n1[i] + BCD_n2[i];
endmodule