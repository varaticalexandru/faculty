clear
clc
close all

%{
    -y''' + y'' - x*y' + 2*y*sin(x) - x^3 = 0
    y''' = y'' - x*y' + 2*y*sin(x) - x^3

    notam
    y1 = y
    y2 = y'
    y3 = y''

    sistemul
    y1' = y2
    y2' = y3
    y3' = y3 - x*y2 + 2*y1*sin(x) - x^3
%}

y0 = [0.5; -0.5; 0.3];
dom = [1 4];
xval = [];
yval = [];
f = @f9_3c;

[xval yval] = ode45(f, dom, y0)
plot(xval, yval(:,1));
hold on
grid
xline(0)
yline(0)
plot(xval, yval(:,2), '--');
plot(xval, yval(:,3), '-.');
legend('y1', 'y2', 'y3');
hold off
