clc
clear
close all

t = -3: 0.1: 3;

f = sin(pi*t) .* cos(pi*t); % linie intrerupta mov
g = sin(pi*t+1) .* cos(pi*t+1); % markere-patrat albastru-deschis cu linie continua


plot(t, f, '--m', t, g, 's-c')


