module func_4 (
                input [1:0] vect,
                output reg func
              );
  
  always @(*) begin
    func = vect[1] & vect[0];
  end
  
  assign func = vect[1] & vect[0];
  
  and myAnd(func, vect[1], vect[0]);
  
endmodule
