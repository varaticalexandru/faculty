clc
clear
A=[4 3 -1;-1 1 1;1 0 3;4 4 3];
B=[2; 0; -1; 1];
[l c]=size(A);
disp('rangul matricei A este=');
disp(rank(A))
if(rank(A)~=rank([A B]))
    disp('Sistemul este incompatibil')
else
    if(rank(A)==c)
        disp('Sistem compatibil determinat')
        disp('Metoda inversei')
        X1=pinv(A)*B
    else
        disp('Sistem compatibil nedeterminat')
        disp('Metoda pseudoinversei')
        X1=pinv(A)*B
    end
    disp('Metoda impartire la stanga')
    X2=A\B
    
end
clear
A=[-6 8 -1;2 -3 0];
B=[1;-5];
[l c]=size(A);
disp('rangul matricei A este=');
disp(rank(A))
if(rank(A)~=rank([A B]))
    disp('Sistemul este incompatibil')
else
    if(rank(A)==c)
        disp('Sistem compatibil determinat')
        disp('Metoda inversei')
        X1=pinv(A)*B
    else
        disp('Sistem compatibil nedeterminat')
        disp('Metoda pseudoinversei')
        X1=pinv(A)*B
    end
    disp('Metoda impartire la stanga')
    X2=A\B
    
end
