%compatibil determinat- solutia / nu este compatibil determinat
A=[4 3 -1; -1 1 1 ;1 3 0];
B=[2; 0; -1];
if(det(A)~=0)
    disp('Sistemul compatibil determinat')
    disp('Metoda inversei')
    X1=inv(A)*B
    disp('Metoda imapartirii dreapta la stanga')
    X2=A\B
else
    disp('Sistemul nu este compatibil determinat')
 end
