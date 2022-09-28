module Add_BCD_tb();
  
  reg [11:0] BCD_n1_tb;
  reg [7:0] BCD_n2_tb;
  wire [15:0] BCD_out_tb;
  
  
  // instantiere DUT
  Add_BCD tb (
                .BCD_n1(BCD_n1_tb),
                .BCD_n2(BCD_n2_tb),
                .BCD_out(BCD_out_tb)
              );
              
  // generare stimuli
  initial begin
    BCD_n1_tb = 12'b0000_0000_0001; // 1
    BCD_n2_tb = 8'b1001_1001; // 99
    
    #2 BCD_n1_tb = 12'b1001_1001_1001; // 999
    BCD_n2_tb = 8'b0000_0000; // 0
    
    #1 BCD_n1_tb = 12'b0001_0100_1001; // 149
    BCD_n2_tb = 8'b1000_1001;  // 89
    
    #2 BCD_n1_tb = 12'b0000_0000_0000; // 0
    BCD_n2_tb = 8'b0000_0000_0000;  // 0
    
    #1 BCD_n1_tb = 12'b1001_1001_1001; // 999
    BCD_n2_tb = 8'b1001_1001;  // 99
  end      
  
  // afisare
  initial begin
    $monitor("BCD_n1=%b | BCD_n2=%b | BCD_out=%b",
              BCD_n1_tb, BCD_n2_tb, BCD_out_tb);
  end
  
endmodule