module test(
            input [15:0]a,
            input [31:0]b,
            input c_en, sel_en, gate_en, x, y, z,
            
            output reg gt_lo_eq,
            output reg [31:0]h_out, err_out,
            output reg [2:0]sum_2a,
            output reg out_xor
          );
  
  integer i;
  
  initial begin
    gt_lo_eq = 1'b0;
    h_out = 32'b0;
    err_out = 32'b0;
    sum_2a = 3'b0;
    out_xor = 1'b0;
  end
  
  always @(c_en, sel_en, gate_en) begin
    
    sum_2a = 3'b0;
    for (i=0; i<=15; i=i+1)
    if ((i%2) != 0)
      sum_2a = sum_2a + a[i];
      
    if (c_en && sel_en && gate_en) begin
      err_out = 32'b1;
    end
    
    else if (c_en) begin
      if (a > b[31:24]) gt_lo_eq = 1'b0;
      else if (a < b[31:24]) gt_lo_eq = 1'b1;
      else if (a == b[31:24]);
    end
    
    if (sel_en) begin
      // b = B3 B2 B1 B0 (4 x 8b)
      // h = B1 B0 B3 B2
      //B3 - 31:24
      //B2 - 23:16
      //B1 - 15:8
      //B0 - 7:0
      h_out = {b[15:8], b[7:0], b[31:24], b[23:16]};
    end
    
    if (gate_en) begin
      out_xor = ((x|y) & (1&(x|z))) | (((x|y)&(x)) | (~(y|z));
      // (x|y & x|z)  | ((x&x | y&x)|(~y & ~z))
      // (x&(y|z) | ((x|(~y & ~z))
      // (x&((y|z) | (~y & ~z)
      
      // x ^ ~(y^z)  
      
    end
        
  end
  
  
  
  


endmodule
            
