clear
clc
close all

% Adams-Bashforth-Moulton
% ec. dif. de ord. 2

% y'' = 2y' - 3x^2*y

% y(0) = -1
% y'(0) = 2

% notam:
% y = y1
% y' = y2

% y1' = y2
% y2' = 2y2 - 3x^2*y1

f = @f9_4;
xval = [];
yval = [];

y0 = [-1; 2];
dom = [1 2.5];

[xval yval] = ode113(f,dom,y0)
plot(xval,yval(:,1));

hold on
grid
xline(0)
yline(0)
hold off


