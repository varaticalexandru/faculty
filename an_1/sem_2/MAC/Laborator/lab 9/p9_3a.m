clear
clc
close all

%{
    y' + y^2 = 3x
    
    y(-1) = 2
    pe [-1, 5]

    y' = 3x - y^2
%}

f = @f9_3a;
xval = [];
yval = [];
dom = [-1 5];
y0 = 2;

[xval yval] = ode113(f, dom, y0)
plot(xval, yval)
hold on
grid
xline(0)
yline(0)
legend('y')