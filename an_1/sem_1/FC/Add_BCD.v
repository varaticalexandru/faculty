module Add_BCD (
                  input [11:0] BCD_n1,  // [0, 999] 12b
                  input [7:0] BCD_n2,   // [0, 99]  8b
                  output reg [15:0] BCD_out    // BCD_n1 + BCD_n2
                );

  /* 
    sa se implementeze algoritmul de adunare a numerelor
    scrise in BCD8421, tinand cont de toate aspectele teoretice
  */
  
  reg carry;
  
  always @(BCD_n1, BCD_n2) begin
    // initializare
    BCD_out = 0;
    carry = 0;
    
    // sumam tetradele 1
    // daca carry e 1 sau suma > 9 ==> corectie de 6
    {carry, BCD_out[3:0]} = BCD_n1[3:0] + BCD_n2[3:0];
    
    if ((carry == 1) || (BCD_out[3:0] > 9)) begin
      BCD_out[7:4] = BCD_out[7:4] + 1;
      BCD_out[3:0] = BCD_out[3:0] + 6;
      carry = 0;
    end
       
    // sumam tetradele 2
    // daca carry 1 sau nr > 9 ==> corectie de 6
    {carry, BCD_out[7:4]} = BCD_out[7:4] + BCD_n1[7:4] + BCD_n2[7:4];
    if ((carry == 1) || (BCD_out[7:4] > 9)) begin
      BCD_out[11:8] = BCD_out[11:8] + 1;
      BCD_out[7:4] = BCD_out[7:4] + 6;
      carry = 0;
    end
    
    // sumam tetradele 3
    // daca carry 1 sau nr > 9 ==> corectie de 6
    {carry, BCD_out[11:8]} =  BCD_out[11:8] + BCD_n1[11:8];
    if ((carry == 1) || (BCD_out[11:8] > 9)) begin
      {carry, BCD_out[11:8]} = BCD_out[11:8] + 6;
    end
    if (carry == 1) begin
      BCD_out[15:12] = 1;
    end
    
  end
  
endmodule