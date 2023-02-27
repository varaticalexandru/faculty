clear
clc
close all

%% Trapezoidala
x = [0 1 2 2.2 4 4.5 4];
y = [1 2.3 3.9 4.2 8.2 10.1 8.2];

I = trapz(x,y)

%% Simpson
a = 0;
b = 4;
f = @integr_func;

I = quad(f, a, b)


