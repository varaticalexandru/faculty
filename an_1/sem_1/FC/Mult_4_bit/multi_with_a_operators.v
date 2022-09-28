module multi_with_a_operatos(
  input [3:0] x, y, 
  output [7:0] pro
);

reg [3:0] b, q, acc;
reg [7:0] temp;
integer n; 

assign  pro = temp;

always@(*) begin 
  b = x; 
  q = y;
  acc = 0;  
  for(n = 4; n > 0; n = n - 1) begin 
    if(q[0]) 
    acc = acc + b;
    temp = {acc, q};
    temp = temp >> 1; // {acc, q} = {acc, q} >> 1;
    q = temp[3:0];
    acc = temp[7:4];
    //{acc, q} = {1'b0, acc, q};  
  end 
end 
endmodule 