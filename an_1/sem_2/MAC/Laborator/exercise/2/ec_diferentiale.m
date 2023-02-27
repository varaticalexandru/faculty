clc
clear
close all

y0 = 2;
dom = [0 1];

f = @sistem_derivate;

[xval yval] = ode113(f, dom, y0)

plot(xval, yval)
hold on
grid
xline(0)
yline(0)
legend('y1')
hold off
