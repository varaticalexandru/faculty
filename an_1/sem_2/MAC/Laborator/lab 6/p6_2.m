clear
clc
close all

% cate solutii are ecuatia?
% sa se determine 2 solutii de valori abs. distincte

x = -10 : 0.05 : 10;

f = exp(cos(x)) - sin(x) - 1;
f1 = 'exp(cos(x)) - sin(x) - 1';
g = exp(cos(x));
h = sin(x) + 1;

plot(x,f);
xline(0)
yline(0)

[x0 y0] = ginput;
close all

options = optimset('TolX', 10^(-10));

for i=1:size(x0)
    [sol_x(i) fval exitflag output] = fzero(f1, x0(i), options);
end

disp('Solutiile ecuatiei transcendente')
sol_x'


