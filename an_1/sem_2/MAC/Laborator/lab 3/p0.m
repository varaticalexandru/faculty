clear
clc
close all

% x1 = -9:0.1:-3+0.1;
% x2 = -3:0.1:3-0.1;
% x3 = 3:0.1:9;
% 
% f1 = sin(5*x1);
% f2 = cos(x2) - cos(3) - sin(15);
% f3 = sin(5*x3);
% 
% t = [x1 x2 x3];
% f = [f1 f2 f3];
% 
% plot(t, f)


% t = 0: 0.1: 6*pi;
% f = sqrt(sin(t) + t.^2);
% polar(t, f)

t = -10*pi: 0.1: 10*pi;
x = t;
y = sin(0.5*t - 3);
z = cos(0.5 * t);

plot3(x, y, z)




