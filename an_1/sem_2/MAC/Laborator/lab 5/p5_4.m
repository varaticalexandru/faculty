clear
clc
close all

syms m x n;
eq = m - x + n/x - m*x - 1;
disp('Solutiile ecuatiei in x:')
sol_x = solve(eq,x)