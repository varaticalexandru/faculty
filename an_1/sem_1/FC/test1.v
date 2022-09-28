module test1(
        input [15:0] a,
        input [15:0] b,
        input [7:0] c,
        input en,
        output reg [7:0] x,
        output reg [7:0] y,
        output reg [3:0] z,
        output reg w
      );
      
     reg [7:0] aux;
      
      initial begin
        // x = -32 (SM) = 10100000
        x = 10100000;
        // y = -10 (C1) = 11110101
        y = 10001010;
        // z = -1 (C2) = 1111
        z = 1111;
        // w = 0
        w = 0;
      end
      
      always @(a or b) begin
        if (en == 1) begin
          // x = max(MSB_a, LSB_a) 
          if (a[15:8]>a[7:0])
            x[7:0] = a[15:8];
          else
            x[7:0] = a[7:0];
            
          // y = (MSB_b & MSB_a) ^ (LSB_b | LSB_a)
          y[7:0] = (b[15:8] & a[15:8]) ^ (b[7:0] | a[7:0]);
          
          // z = suma bitilor lui c
          z = c[0]+c[1]+c[2]+c[3]+c[4]+c[5]+c[6]+c[7];
          
          // w = XOR intre bitii(c ^ MSB_b & LSB_a| 0xAA)
          aux[7:0] = c[7:0] ^ b[15:8] & a[7:0]| 10101010;
          w = aux[0]^aux[1]^aux[2]^aux[3]^aux[4]^aux[5]^aux[6]^aux[7];
      end
    end
          
          
endmodule
        