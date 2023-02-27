clc
clear
close all

syms x y z;

eq1 = x + y + z - 4;
eq2 = 3*x - 7*y - 12;


disp(solve(eq1, eq2, y, z))
disp(solve(eq1, eq2, x, z))
disp(solve(eq1, eq2, x, y))

