clear
clc
close all

coef = [2 -3 0 3 -10 -8];

disp('Solutiile ecuatiei 1:')
sol = roots(coef)

disp(blanks(2)')

coef1 = [-1 -2 -4 -2];
disp('Solutiile ecuatiei 2:')
sol1 = roots(coef1)
disp('Solutiile reale ale ecuatiei 2:')
sol_r = sol1(imag(sol1) == 0)

