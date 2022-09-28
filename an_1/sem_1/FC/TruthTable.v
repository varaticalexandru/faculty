module TruthTable (
                    input a,b,c,
                    output reg X
                  );
                  
  always @(a,b,c) begin
    
      if ((~a) & (~b) & (~c)) begin
        X = 1'b1;
      end
      else if ((~a) & (~b) & (c)) begin
        X = 1'b0;
      end
      else if ((~a) & (b) & (~c)) begin
        X = 1'b1;
      end
      else if ((~a) & (b) & (c)) begin
        X = 1'b1;
      end
      else if ((a) & (~b) & (~c)) begin
        X = 1'b0;
      end
      else if ((a) & (~b) & (c)) begin
        X = 1'b1;
      end
      else if ((a) & (b) & (~c)) begin
        X = 1'b1;
      end
      else if ((a) & (b) & (c)) begin
        X = 1'b0;
      end
    
    // forma minimizata : X = (a & ~b & c) | ( ~a & b) | ( ~a & ~c) | (b & ~c);
    
  end
         
                  
endmodule
