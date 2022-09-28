module func_5(
              input [1:0]vect,
              output reg func
            );
            
  always @(*) begin   // atribuire procedurala
    func = & vect;
  end
      
    
              

endmodule
