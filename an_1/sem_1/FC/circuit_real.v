/* 
Din pacate, nu traim intr-o lume ideala. Din acest motiv, orice circuit, inclusiv portile logice,
au asa numite intarzieri. Aceste intarzieri ne pot afecta rezultatul unei operatii, dupa cum urmeaza
      _________________            ________________
a----|>in1             |          |                |
     |  [and_gate] out>|-5- w ----|>in1            |
b-|--|>in2             |          |                |
  |  |_________________|          |     [OR]   out>|1--c
  |                               |                |
  |-------------------------------|>in2            |
                                  |________________|

Vom considera ca poarta and are o intarziere de 5 unitati de tip, iar out va avea o intarziere de 1 unitate de timp.
Asta inseamna, ca daca la momentul x, la intrarea portii avem intrarile 1 si 0, abia dupa 5 unitati de timp vom vedea rezultatul.

Daca am pune valorile pe axa timpului, ar arata in felul urmator:
t - 0  1  2  3  4  5  6  7  8  9  10  11
        ____      ______
a 1    |    |    |
  0 ___|    |____|
             ____________
b 1         |    
  0 ________|    

     
w 1 xxxxxxxxxxxxxxx           
  0 xxxxxxxxxxxxxxx__ ...
                      ____ 
c 1 xxxxxxxxxxxxxxxxxx     ...
  0 xxxxxxxxxxxxxxxxxx

Motivul pentru care c este 1 la final, este ca la unitatea de timp 5, w = 0, dar b s-a schimbat in 1, rezultand 1.

Challenge pentru voi: Creeati un testbench la acest circuit ideal si creeati a si ba ca mai sus si observati rezultatul 
c si diferenta de c_ideal
*/

module circuit_real(
                    input a,b,
                    output c 
                    );
                    
    wire w;
    
    or_gate (#5) or_ (.in1(a), .in2(b), .out(w));
    and_gate (#1) and_ (.in1(w), .in2(b), .out(c));
    
    assign c_ideal = (a & b) | b;
endmodule