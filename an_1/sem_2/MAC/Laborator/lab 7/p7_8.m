clear
clc
close all

% problema de optimizare fara restrictii (unconstrained)
% metode cvasi-Newton (fminunc)

f = @f7_8;

x0 = [1  0];

[xmin fmin exitflag output] = fminunc(f,x0)
