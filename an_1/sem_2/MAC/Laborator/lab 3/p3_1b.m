clear
clc
close all

t = -3 : 0.1 : 3;

f = sin(pi*t) .* cos(pi*t);
g = sin(pi*t+1) .* cos(pi*t+1);

plot(t,f,'--m', t,g,'sc-');
xlabel('x');
ylabel('y');
title('Titlu');
