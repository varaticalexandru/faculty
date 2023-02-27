clc
clear
close all

% 2.^x = cos(pi*x + 0.5) + 2.5

% intervalul de reprezentare grafica
x = 0: 0.05 :2;

% reprezentarea grafica a celor 2 functii
plot(x, 2.^x, 'b',x, cos(pi*x+0.5) + 2.5, 'r:')

% stabilirea limitelor de reprezentare
axis([0 2 1 4])

% citirea coord. pct. de intersectie

[x0, y0] = ginput(3)

sol = [];
for i=1:3
    sol(i) = fzero('ectrans3', x0(i));
end

sol
