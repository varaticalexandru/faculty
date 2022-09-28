module junk_tb(
                    input a,b,
                    output reg func
                  );
  
  always @(*) begin
    func = a & b;
  end
  
endmodule
