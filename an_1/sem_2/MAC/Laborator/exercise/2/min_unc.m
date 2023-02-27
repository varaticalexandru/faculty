clear
clc
close all

%% unconstrained
p0 = [0.1 0.1];
f = @fmin_func;

[xmin fmin] = fminsearch(f, p0)

%% constrained
a = 0;
b = 1;
f = @fmin_func;

[xmin fmin] = fminbnd(f, a, b)

