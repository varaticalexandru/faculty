clear
clc
close all

format shortg

% 2x + 3 = 6 + sqrt(x-1)
coef = [4 -13 10];
disp('Solutiile ecuatiei algebrice: ')
sol = roots(coef)
disp('Solutiile reale ale ecuatiei algebrice:')
sol_r = sol(sol>=1.5 & imag(sol)==0)
