clear
clc
close all

% problema de optimizare fara restrictii
% cautare simplex Nelder-Mead (fminsearch)

f = @f7_9;
x0 = [0.6 -0.2 -0.1];

[xmin fmin exitflag output] = fminsearch(f,x0)