module special_five_bit_FAC_tb();

  reg [3:0] A, B;
  reg Q0;
  wire [4:0] S;

  // instantiere DUT
  special_five_bit_FAC instantiere (
                          .A(A),
                          .B(B),
                          .Q0(Q0),
                          .S(S)
                        );
  
  // generare stimuli
  initial begin
    A[3:0] = {1'b0, 4'b0111};
    B[3:0] = {1'b0, 4'b1111};
    Q0 = 1'b1;
  end

endmodule
