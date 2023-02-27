clear
clc
close all

x0 = -0.5;

% functia
% f = 'sin(x) + (x/3 - 0.5).^3 + 1';
f = @f6_1;

% setarea preciziei
options = optimset('TolX', 10^(-10));

% calcularea solutiei
[x fval exitflag output] = fzero(f, x0, options);
% [x fval exitflag output] = fzero('f6_1', x0, options)

disp('Solutiei ecuatiei transcendente:')
x