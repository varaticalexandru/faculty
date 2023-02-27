clear
clc
close all

% coord. logaritmice (lg(t), lg(f(t)))

%t = 1 : 0.1 : 5;
t = logspace(1,5);
f = exp(3*t);

loglog(t,f);
grid
xlabel('lg(t)');
ylabel('lg(f(t))');
title('f(t) = e^3t');
