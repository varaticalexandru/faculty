clc
clear
close all

A=[]; B=[]; Suma =[]; Produs=[]; AstrB=[]; rankB=[];

    format shortg

    for i=1:4
        for j=1:4
            A(i,j) = round(1/(i+j), 2);
        end
    end
    
 
    for i=1:4
        for j=1:4
            if i==j B(i,j) = 1;
            elseif i>j B(i,j) = i+j;
            elseif i<j B(i,j) = i-j;
            end
        end
    end

    A
    B
    Suma = A+B
    Produs = A*B
    CubA = A^3
    AstB = A\B
    rangB = rank(B)