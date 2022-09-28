module func_1 (
                input a,b,
                output reg func
              );
  always @(*) begin
    func = a & b;   // func este declarat ca reg
  end
              
endmodule
