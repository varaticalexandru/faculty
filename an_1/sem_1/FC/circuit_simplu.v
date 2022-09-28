/* 
Vom creea urmatorul circuit, ca mai jos:
      _________________            _____________________
a----|>in1             |          |                     |
     |  [and_gate] out>|-- w -----|>in1                 |
b-|--|>in2             |          |                     |
  |  |_________________|          |     [or_gate]   out>|---c
  |                               |                     |
  |-------------------------------|>in2                 |
                                  |_____________________|
                                  
Intr-o lume ideala, rezultatul expresiei ar fi: c = (a & b) | b

*/




module circuit_simplu(
                      input a, b,
                      output c, c_ideal
                      );
                      
    wire w;
                      
    and_gate and_ (.in1(a), .in2(b), .out(w));
    or_gate or_ (.in1(w), .in2(b), .out(c));
    assign c_ideal = (a & b) | b;
  
  
endmodule
