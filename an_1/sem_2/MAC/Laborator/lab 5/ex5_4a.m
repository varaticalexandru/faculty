clear
clc
close all


% definirea obiectelor simbolice
syms x a b;

% exprimarea membr. stang al ec. adus la forma 
% f(x) = 0
f = (a*x-b)/(a*x+b) - exp(-a);

% rezolvarea ec. in raport cu x
sol_x = solve(f,x)
sol_b = solve(f,b)

% sol = solve(a*(exp(-a)-1)*x + b*(exp(-a)+1), x, 'ReturnConditions',true)








% syms a b;
% coef = [a-a*exp(-a), -b*(exp(-a)+1)];
% 
% disp('Solutiile ecuatiei algebrice: ')
% sol = simplify(roots(coef))
% 
% pause
% clear
% clc
% 
% syms a b;
% coef = [a^2-b^2, 0, 4*a*b];
% sol = simplify(roots(coef))

