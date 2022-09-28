module checkP(
              input [2:0] n,
              output reg isP
              );
              
  always @(*) begin
    isP = ((~n[2])& n[1] &(~n[0])) | ((~n[2]) & n[1] & n[0])| (n[2] & (~n[1]) & n[0]) | (n[2] & n[1] & n[0]);
  end

endmodule