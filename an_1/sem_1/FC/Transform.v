module Transform (
                  input [11:0] NR_IN,  // [0; 999] in BCD => 12b
                  output reg [14:0] NR_OUT,
                  output integer NR_OUT_DEC
                );
                
     reg [11:0] aux, bcd;
     integer int, cifra_1, cifra_2, cifra_3;           
                
                
    always @(NR_IN) begin
      aux = 12'b0;
      NR_OUT = 15'b0;
      aux = NR_IN;
      
      cifra_1 = aux[11:8];
      cifra_2 = aux[7:4];
      cifra_3 = aux[3:0];
      
      int = (cifra_1*100) + (cifra_2*10) + (cifra_3*1);
      
      
      if ((int>=0) && (int <=99)) begin // E3
        NR_OUT[14:10] = NR_IN[11:8] + 5'b00011;
        NR_OUT[9:5] = NR_IN[7:4] + 5'b00011;
        NR_OUT[4:0] = NR_IN[3:0] + 5'b00011;
      end
      else if ((int>=100) && (int<=449)) begin // 2-din-5 74210
        case (cifra_1)
          0 : NR_OUT[14:10] = 5'b11000;
          1 : NR_OUT[14:10] = 5'b00011;
          2 : NR_OUT[14:10] = 5'b00101;
          3 : NR_OUT[14:10] = 5'b00110;
          4 : NR_OUT[14:10] = 5'b01001;
          5 : NR_OUT[14:10] = 5'b01010;
          6 : NR_OUT[14:10] = 5'b01100;
          7 : NR_OUT[14:10] = 5'b10001;
          8 : NR_OUT[14:10] = 5'b10010;
          9 : NR_OUT[14:10] = 5'b10100;
        endcase
        
        case (cifra_2)
          0 : NR_OUT[9:5] = 5'b11000;
          1 : NR_OUT[9:5] = 5'b00011;
          2 : NR_OUT[9:5] = 5'b00101;
          3 : NR_OUT[9:5] = 5'b00110;
          4 : NR_OUT[9:5] = 5'b01001;
          5 : NR_OUT[9:5] = 5'b01010;
          6 : NR_OUT[9:5] = 5'b01100;
          7 : NR_OUT[9:5] = 5'b10001;
          8 : NR_OUT[9:5] = 5'b10010;
          9 : NR_OUT[9:5] = 5'b10100;
        endcase
        
        case (cifra_3)
          0 : NR_OUT[4:0] = 5'b11000;
          1 : NR_OUT[4:0] = 5'b00011;
          2 : NR_OUT[4:0] = 5'b00101;
          3 : NR_OUT[4:0] = 5'b00110;
          4 : NR_OUT[4:0] = 5'b01001;
          5 : NR_OUT[4:0] = 5'b01010;
          6 : NR_OUT[4:0] = 5'b01100;
          7 : NR_OUT[4:0] = 5'b10001;
          8 : NR_OUT[4:0] = 5'b10010;
          9 : NR_OUT[4:0] = 5'b10100;
        endcase
      end
      else if((int>=450) && (int<=899)) //2-din-5 63210
      begin
        case (cifra_1)
          0 : NR_OUT[14:10] = 5'b00110;
          1 : NR_OUT[14:10] = 5'b00011;
          2 : NR_OUT[14:10] = 5'b00101;
          3 : NR_OUT[14:10] = 5'b01001;
          4 : NR_OUT[14:10] = 5'b01010;
          5 : NR_OUT[14:10] = 5'b01100;
          6 : NR_OUT[14:10] = 5'b10001;
          7 : NR_OUT[14:10] = 5'b10010;
          8 : NR_OUT[14:10] = 5'b10100;
          9 : NR_OUT[14:10] = 5'b11000;
        endcase
        
        case (cifra_2)
          0 : NR_OUT[9:5] = 5'b00110;
          1 : NR_OUT[9:5] = 5'b00011;
          2 : NR_OUT[9:5] = 5'b00101;
          3 : NR_OUT[9:5] = 5'b01001;
          4 : NR_OUT[9:5] = 5'b01010;
          5 : NR_OUT[9:5] = 5'b01100;
          6 : NR_OUT[9:5] = 5'b10001;
          7 : NR_OUT[9:5] = 5'b10010;
          8 : NR_OUT[9:5] = 5'b10100;
          9 : NR_OUT[9:5] = 5'b11000;
        endcase
        
        case (cifra_3)
          0 : NR_OUT[4:0] = 5'b00110;
          1 : NR_OUT[4:0] = 5'b00011;
          2 : NR_OUT[4:0] = 5'b00101;
          3 : NR_OUT[4:0] = 5'b01001;
          4 : NR_OUT[4:0] = 5'b01010;
          5 : NR_OUT[4:0] = 5'b01100;
          6 : NR_OUT[4:0] = 5'b10001;
          7 : NR_OUT[4:0] = 5'b10010;
          8 : NR_OUT[4:0] = 5'b10100;
          9 : NR_OUT[4:0] = 5'b11000;
        endcase
      end
      else if((int>=900) && (int<=999)) begin
        NR_OUT_DEC = int;
      end
          
      
    end
    
endmodule
