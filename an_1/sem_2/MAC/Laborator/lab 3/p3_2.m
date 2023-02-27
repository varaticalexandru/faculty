clear
clc
close all

% coord. polare (r=f(t), tau=t)

t = 0 : pi/100 : 6*pi;
f = sqrt(sin(t) + t.^2);

polarplot(t, f);


