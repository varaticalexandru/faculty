module shift_multiplication (
                              input [3:0] X,Y,
                              output reg [7:0] P
                            );

  reg [3:0] M, Q;{M, Q;}
  reg [4:0] A;
  integer i;
  
  always @(*) begin
    A[4:0] = 5'b0;
    B[3:0] = X[3:0];
    Q[3:0] = Y[3:0];
    
    for (i=3; i>=0; i=i-1) begin
      if (Q[0])
        A[4:0] = A[4:0] + B[3:0];
      {acc,Q} >> 1;
    end
  
  end
endmodule