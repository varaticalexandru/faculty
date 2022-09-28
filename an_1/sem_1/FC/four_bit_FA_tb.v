module four_bit_FA_tb();
  
  reg [3:0] A, B;
  wire [4:0] S;

  // instantiere DUT
  four_bit_FA instantiere (
                          .A(A),
                          .B(B),
                          .S(S)
                        );
  
  // generare stimuli
  initial begin
    A[3:0] = 4'b1111;
    B[3:0] = 4'b1111;
  end

endmodule
  
