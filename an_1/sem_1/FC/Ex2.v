module Ex2 (
            input [7:0] a,b,
            input [15:0] c,
            input comp_en, minmax_en, sel_ab, sel_c, sel_minmax,
            output reg comp_out,
            output reg [7:0] minmax_out,
            output reg [2:0] sum_ab,
            output reg [15:0] xor_out
          );
          
  integer i;
          
  initial begin
    comp_out = 1'b1;
    minmax_out = 8'b1111_1111;
    sum_ab = 3'b111;
    xor_out = 16'b1111_1111_1111_1111;
  end        
  
  always @(comp_en, minmax_en) begin
    
    if (comp_en) begin
      if (a>b) comp_out = 1'b0;
      else if (a<b) comp_out = 1'b1;
      else if (a==b) comp_out = ~comp_out;
    end
    
    if (minmax_en) begin
      if ((~sel_ab) & (~sel_c) & (~sel_minmax)) begin
        if (a<c[7:0]) minmax_out = a;
        else minmax_out = c[7:0];
      end
      else if ((~sel_ab) & (~sel_c) & (sel_minmax)) begin
        if (a>c[7:0]) minmax_out = a;
        else minmax_out = c[7:0];
      end
      else if ((~sel_ab) & (sel_c) & (~sel_minmax)) begin
        if (a<c[15:8]) minmax_out = a;
        else minmax_out = c[15:8];
      end
      else if ((~sel_ab) & (sel_c) & (sel_minmax)) begin
        if (a>c[15:8]) minmax_out = a;
        else minmax_out = c[15:8];
      end
      else if ((sel_ab) & (~sel_c) & (~sel_minmax)) begin
        if (b<c[7:0]) minmax_out = b;
        else minmax_out = c[7:0];
      end
      else if ((sel_ab) & (~sel_c) & (sel_minmax)) begin
        if (b>c[7:0]) minmax_out = b;
        else minmax_out = c[7:0];
      end
      else if ((sel_ab) & (sel_c) & (~sel_minmax)) begin
        if (b<c[15:8]) minmax_out = b;
        else minmax_out = c[15:8];
      end
      else if ((sel_ab) & (sel_c) & (sel_minmax)) begin
        if (b>c[15:8]) minmax_out = b;
        else minmax_out = c[15:8];
      end
    end
    
    for (i=0; i<8; i=i+1) begin
      if ((i%2)==0) sum_ab = sum_ab + a[i];
      if ((i%2)!=0) sum_ab = sum_ab + b[i];
    end
    
    // xor_out = c ^ X
    // X = {Y, Z}
    // Y = a & b;
    // Z = a | b;
    
    xor_out = c ^ ({(a&b), (a|b)});
    
  end
          
endmodule