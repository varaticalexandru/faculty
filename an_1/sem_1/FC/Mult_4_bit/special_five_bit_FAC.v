// A = A + B 

module special_five_bit_FAC (
                input [3:0] A, B,
                input Q0,
                output reg[4:0] S
                );

    reg Cin1, Cin2, Cin3, Cin4;
    reg Cout0, Cout1, Cout2, Cout3, Cout4;    
    
    
    always @(*) begin
      if (Q0) begin
        S[0] = A[0] ^ B[0] ^ 0;
        Cout0 = ((A[0]^B[0])&(0)) | (A[0]&B[0]);
        Cin1 = Cout0;
            
        S[1] = A[1] ^ B[1] ^ Cin1;
        Cout1 = ((A[1]^B[1])&(Cin1)) | (A[1]&B[1]);
        Cin2 = Cout1;        
      
        S[2] = A[2] ^ B[2] ^ Cin2;
        Cout2 = ((A[2]^B[2])&(Cin2)) | (A[2]&B[2]);
        Cin3 = Cout2;
                  
        S[3] = A[3] ^ B[3] ^ Cin3;
        if (Q0) begin
        S[0] = A[0] ^ B[0] ^ 0;
        Cout0 = ((A[0]^B[0])&(0)) | (A[0]&B[0]);
        Cin1 = Cout0;
            
        S[1] = A[1] ^ B[1] ^ Cin1;
        Cout1 = ((A[1]^B[1])&(Cin1)) | (A[1]&B[1]);
        Cin2 = Cout1;        
      
        S[2] = A[2] ^ B[2] ^ Cin2;
        Cout2 = ((A[2]^B[2])&(Cin2)) | (A[2]&B[2]);
        Cin3 = Cout2;
                  
        S[3] = A[3] ^ B[3] ^ Cin3;
        Cout3 = ((A[3]^B[3])&(Cin3)) | (A[3]&B[3]);
        Cin4 = Cout3;         
    
        S[4] =  Cin4;
      end
      else begin
        S = A;
      end
    end
  end                         
 
endmodule