clear
clc
close all

coef = [1 1 -2 4 11 -45 -50 0];

disp('Solutiile ecuatiei:')
sol = roots(coef)

disp('Solutiile ecuatiei real pozitive:')
sol_p = sol(real(sol)>0)
