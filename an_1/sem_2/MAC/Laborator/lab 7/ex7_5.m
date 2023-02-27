clear
clc
close all

% sa se determine punctul de minim situat in vecinatatea
% x0 = 2 si minimul local al functiei

% f(x) = x - sin(x*pi) - 3

x0 = 2;
f = @f7_5;

[xmin fval, exitflag, output] = fminsearch(f,x0)
