module supl0 (
  input [3:0] in_,
  output reg [4:0] out_
  );
  
  /* bitSemn (1 bit) Numar (minim 4 biti) */
  
  always @(*) begin
    /* bitul de semn */
    // code
    
    out_[4] = in_[3];
    
    
    /* valoarea numarului in modul */
    // code
    if (out_[4] == 0) begin
      _out[3] = 0;
      out_[2:0] = in_[2:0];
      // out_[3:0] = {1'b0, in_[2:0]};
    end
    else begin
      
      out_[3:0] = ~({1'b1, (in_[2:0]} - 1);
      
      /* SM     10101 = -5 = out_
         C1  ~  11010 (negam bitii)
         C2 +1  11011 = in_
      */
      
      /*
          -8 C2 =  1000
          -8 SM = 11100
      */
      
      /*
          -8 SM = 11000
             C1 = 10111
             C2 = 11000
      */
    end
  end
endmodule
         
