module supl (
              input [31:0] a,b,
              input en,sw,
              output reg [31:0]xor0,
              output reg o,
              output reg [8:0] sum
            );
            
            integer i;
            
            
    initial begin
      // initial, toate iesirile modului setam 0
      xor0 = {32{1'b0}}; // de 32 ori avem 1b de 0
      o = 1'b0;         // pe 1b avem 0
      sum = {9{1'b0}};
    end
    
    always @(a or b) begin
      if (sw == 1) begin
        if (en == 1) begin
          xor0 = a ^ (b>>4);
        end
        else if (en == 0) begin
          //xor0 = {a[31:16], b[31:16]} ^ {a[15:0], b[15:0]};  //concatinare
          xor0[31:16] = a[31:16] ^ a[15:0];
          xor0[15:0] = b[31:16] ^ b[15:0];
        end
        o = ~(((a[0]&b[0])^b[0])|a[0]);
      end
      
    sum = 0;
    for (i=0; i<32; i=i+1)
      if (a[i] == 0)
        sum = sum + i;
      
    end
endmodule
      
        
  
