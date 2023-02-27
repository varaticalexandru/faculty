clear
clc
close all

% Runge-Kutta ord. 4-5

% Sis. de ec. dif. ord. 1
% y1' = y1 + y2
% y2' = x - y1

% Notam:
% y1 = y
% y2 = y'

% Cond. init:
% y1(0) = 0.1
% y2(0) = 0.2

f = @f9_5;
xval = [];
yval = [];
dom = [0 10];
y0 = [0.1; 0.2];

[xval yval] = ode45(f,dom,y0)
plot(xval,yval(:,1));
hold on
plot(xval,yval(:,2),'--');
legend('y1','y2');
xline(0);
yline(0)
grid;
