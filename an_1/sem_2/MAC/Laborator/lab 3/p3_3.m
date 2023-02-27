clc
clear
close all

% coordonate logaritmice ( lg(t), lg(f(t)) )
% f(t) = e^(3*t)
% t = [1, 5]

t = 1: 0.1: 5;
f = exp(1) .^ (3*t);

loglog(t, f)

