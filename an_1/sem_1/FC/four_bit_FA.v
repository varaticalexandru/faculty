module four_bit_FA (
                input [3:0] A, B,
                output [4:0] S
                );

    // w - legatura intre FAC-uri de la Cout - Cin            
    wire w1, w2, w3, w4;     
    
    // Instantiere FAC-uri
    FA fac0 (
              .A(A[0]),
              .B(B[0]),
              .Cin(1'b0),
              .Cout(w1),
              .S(S[0])
            );
            
     FA fac1 (
              .A(A[1]),
              .B(B[1]),
              .Cin(w1),
              .Cout(w2),
              .S(S[1])
            );
            
     FA fac2 (
              .A(A[2]),
              .B(B[2]),
              .Cin(w2),
              .Cout(w3),
              .S(S[2])
            );
            
     FA fac3 (
              .A(A[3]),
              .B(B[3]),
              .Cin(w3),
              .Cout(S[4]),
              .S(S[3])
            );    
                                    
 
endmodule

