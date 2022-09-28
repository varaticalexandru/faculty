module lab5 (
              input [7:0] in,
              output a,b,c,d
            );

  
assign  a = in[7]&in[6];
assign  b = in[5]|in[4];
assign  c = in[3]^in[2];
assign  d = (~in[1]) & (~in[0]);

endmodule