clear
clc
close all

A = [5 4 1; 6 3 2; 1 1 1];
b = [0 5 -7]';
X = []';

% metoda inversarii matriceale
if (det(A) ~= 0)
    X = inv(A) * b
else
   disp('Sistemul nu este compatibil determinat')
end