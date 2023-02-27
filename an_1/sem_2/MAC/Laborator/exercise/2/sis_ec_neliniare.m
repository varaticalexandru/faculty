clear
clc
close all

%% simbolic
syms x y z;

eq1 = x + z - 2*y;
eq2 = x + y + z - 30;
eq3 = (x-5)*z - (y-4)^2;
sol = solve(eq1,eq2,eq3)

for i = 1 : length(sol.x)
    disp([sol.x(i) sol.y(i) sol.z(i)])
end

%% numeric
p0 = [20; 25; 22];
% options = optimset('TolX', 10^(-30), 'TolFun', 10^(-30));
f = @sistem_neliniar;
[sol fval] = fsolve(f,p0, options)



