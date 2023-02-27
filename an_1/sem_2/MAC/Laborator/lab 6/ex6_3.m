clc
clear
close all

f = @f6_3;

a = 0;
b = 2;

% intervalul de reprezentare grafica
x = a : 0.005 : b;

g = 2.^x;
h = cos(pi.*x + 0.5) + 2.5;
x_sol = [];

options = optimset('TolX', 10^(-10));

xline(0);
yline(0);    
plot(x,g,'b-', x,h,'r:')
[x0 y0] = ginput;
close all

for i = 1 : numel(x0)
    x_sol(i) = fzero(f,x0(i),options);
end

disp('Solutiile ecuatiei transcendente: ');
x_sol
