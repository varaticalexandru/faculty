module qwerty();
  
  
  reg [11:0] a;
  reg [7:0] b;
  reg [15:0] c;
  reg carry;
  reg [4:0] temp;
  
  initial begin
    a = 16'b0000_1001_1001_1001;
    b = 8'b0001_0000;
    c = {16{1'b0}};
    
    c[4:0] = a[3:0]+b[3:0];
    
    
    if (c[5]==1)
      carry=1;
    else
      carry=0;
      
    if ((carry==1) || (c[3:0]>4'b1001)) begin
      temp = c[3:0] + 4'b0110;
      carry = temp[4];
      c[3:0] = temp[3:0];
    end
    
     $display("carry =%b", carry);
     if (carry==1) begin
       c[8:4] = a[7:4]+b[7:4];
       c[8:4] = c[8:4]+5'b1;
       $display("c = %b temp = %b", c[8:4],temp);
    end
    else begin
       c[8:4] = a[7:4]+b[7:4];
       $display("else c = %b temp = %b", c[8:4],temp);
  end 
    if (c[8]==1)
      carry=1;
    else
      carry=0;
      
    
      
    if ((carry==1) || (c[7:4]>4'b1001)) begin
      temp = c[7:4] + 4'b0110;
      carry = temp[4];
      c[7:4] = temp[3:0];
    end
    $display("2c = %b temp = %b", c[8:4],temp);
    if (carry==1)
      c[11:8] = a[11:8] + 4'b1;
    if ((carry==1) || (c[11:8]>4'b1001)) begin
      c[12:8]=c[11:8]+ 4'b0110;
    end
    $display("c = %b ", c);
  end
endmodule
    
