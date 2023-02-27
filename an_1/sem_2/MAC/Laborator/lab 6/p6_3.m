clear
clc
close all

syms a b x p;
eq = 2 * b * (cos(x))^2 + 2*a*sin(x)*cos(x) - p*sqrt(a^2+b^2) + b;
simplify(solve(eq, x))