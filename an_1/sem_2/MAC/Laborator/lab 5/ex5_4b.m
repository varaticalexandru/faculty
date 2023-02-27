clear
clc
close all

syms a b x;

f = (a*x^2+2*b)/(b*x^2-2*a) - b/a;
sol_x = solve(f,x, 'ReturnConditions',true);
sol_x.x
sol_x.conditions