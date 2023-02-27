clear
clc
close all

% sa se determine pe cale simbolica toate tripletele
% (a,b,c) care indeplinesc simultan conditiile:
% i) a,b,c - pr.aritm.
% ii) suma a+b+c = 30
% iii) a-5, b-4, c - pr.geom.


% Sistemul format:
% a + c = 2b
% a + b + c = 30
% (a-5)*c = (b-4)^2

% Sistemul in forma canonica:
% a - 2b + c = 0
% a + b + c - 30 = 0
% (a-5)*c - (b-4)^2 = 0


syms a b c;

eq1 = a - 2*b + c;
eq2 = a + b + c - 30;
eq3 = (a-5)*c - (b-4)^2;

sol = solve(eq1,eq2,eq3, a,b,c);

sol_1 = [sol.a(1),sol.b(1),sol.c(1)]
sol_2 = [sol.a(2),sol.b(2),sol.c(2)]
