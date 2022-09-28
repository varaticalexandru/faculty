module Multiply_4_bit(
                      input [3:0]X,Y,   // deinmultit, multiplicator
                      input clk,        // clock
                      input start,      // start
                      output reg[7:0]P, // produs final
                      output reg stop   // stop
                    );
    
    reg [3:0]B, Q;               //  deinmultit, multiplicator
    reg [4:0]A;                  //  acumulator
    reg [4:0]sum, Cin, Cout;     //  registru pt suma A+B, carry in, carry out 
    reg [8:0]shift_temp;         //  registru pt {A, Q} >> 1
    
    
    always @(posedge clk) begin
        // initializare
        if (start) begin 
          B = X;
          Q = Y;
          A = 5'b0;
          stop = 1'b0;
        end
        
        //if (Q[0]) A = A + B;
        if (~start) begin
          repeat (4) begin
            if (Q[0]) begin
              // A = A + B
              sum[0] = A[0] ^ B[0] ^ 0;
              Cout[0] = ((A[0]^B[0])&(0)) | (A[0]&B[0]);
              Cin[1] = Cout[0];
            
              sum[1] = A[1] ^ B[1] ^ Cin[1];
              Cout[1] = ((A[1]^B[1])&(Cin[1])) | (A[1]&B[1]);
              Cin[2] = Cout[1];        
      
              sum[2] = A[2] ^ B[2] ^ Cin[2];
              Cout[2] = ((A[2]^B[2])&(Cin[2])) | (A[2]&B[2]);
              Cin[3] = Cout[2];
                  
              sum[3] = A[3] ^ B[3] ^ Cin[3];
              Cout[3] = ((A[3]^B[3])&(Cin[3])) | (A[3]&B[3]);
              Cin[4] = Cout[3];         
    
              sum[4] =  Cin[4];
            
              A = sum;
            
              //{A, Q} = {A, Q} >> 1;
              shift_temp = {1'b0, A, Q[3:1]};
              A = shift_temp[8:4];
              Q = shift_temp[3:0];
            
            end
            else begin
              //{A, Q} = {A, Q} >> 1;
              shift_temp = {1'b0, A, Q[3:1]};
              A = shift_temp[8:4];
              Q = shift_temp[3:0];
            end 
          end 
          
          stop = 1;
          P = {A, Q};
        end
        
        
    end 
    
endmodule