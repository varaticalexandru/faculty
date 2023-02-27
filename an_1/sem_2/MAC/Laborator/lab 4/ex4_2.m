clear
clc
close all

A = [2 -3 0; -6 8 -1; 0 3 4];
b = [7 -5 1]';
X = []';

% metoda impartirii la stanga

if (det(A) ~= 0)
    X = A \ b
else
    disp('Sistemul nu este compatibil determinat')
end


    