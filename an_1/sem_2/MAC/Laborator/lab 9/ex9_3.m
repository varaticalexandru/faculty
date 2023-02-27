clear
clc
close all

% Runge-Kutta de ord. 2-3
% ec. dif. de ord. 1
% y' = x^2(y+1)

y0 = 1;
dom = [1 2];

[xval yval] = ode23('f9_3', dom, y0)
plot(xval,yval);
grid
xline(0)
yline(0)
