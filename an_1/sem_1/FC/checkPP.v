module checkPP(); 
  
  reg [3:0] a;


initial begin
  a[3:0] = 4'b0111;
  $display("a = %d", a[3:0]*10);
end

endmodule
