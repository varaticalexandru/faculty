clear
clc
close all

%{
    Ec. dif. de ord. 2:
    y'' - y' = 2ysin(t)

    Cond. init:
    y(0) = -1
    y'(0) = 2
    
    pe [0, 6]

    y'' = y' + 2ysin(t)
    
    notam
    y1 = y
    y2 = y'

    sistemul
    y1' = y2
    y2' = y2 + 2*y1*sin(t)
%}

f = @f9_3b;
dom = [0 6];
y0 = [-1; 2];

xval = [];
yval = [];

[xval yval] = ode45(f, dom, y0)
plot(xval, yval(:,1));
hold on
grid
xline(0)
yline(0)
plot(xval, yval(:,2));
legend('y1','y2');
hold off
