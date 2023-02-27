clear
clc
close all



% matricea coef. sis. 1
A = [1     0.5     0.3333   0.25
    0.5    0.3333  0.25     0.2 
    0.3333 0.25    0.2      0.1667
    0.25    0.2    0.1667   0.1429];
b = [0.1; 0; 0.1; 0];

sol = A\b
nrc = cond(A)
nrcc = rcond(A)

% matricea coef. sis. 2
A1 = A;
A1(4,4) = 0.1436;
sol1 = A1\b
nrc1 = cond(A1)
nrcc1 = rcond(A1)

% compararea sol.
dif = abs(sol - sol1)

disp('Sistemul este slab conditionat')

% syms x1 x2 x3 x4;
% e1 = x1 + 0.5*x2 + 0.3333*x3 + 0.25*x4 == 0.1;
% e2 = 0.5*x1 + 0.3333*x2 + 0.25*x3 + 0.2*x4 == 0;
% e3 = 0.3333*x1 + 0.25*x2 + 0.2*x3 + 0.1667*x4 == 0.1;
% e4 = 0.25*x1 + 0.2*x2 + 0.1667*x3 + 0.1429*x4 == 0;
% 
% eqns = [e1 e2 e3 e4];
% vars = [x1 x2 x3 x4];
% 
% [x1 x2 x3 x4] = solve(eqns, vars);
% 
% disp('x1 = ')
% disp(vpa(x1))
% 
% disp('x2 = ')
% disp(vpa(x2))
% 
% disp('x3 = ')
% disp(vpa(x3))

% disp('x4 = ')
% disp(vpa(x4))