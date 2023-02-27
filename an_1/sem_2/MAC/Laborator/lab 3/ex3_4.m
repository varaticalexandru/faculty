clear
clc
close all

% intervalul de reprezentare (vector cu pas liniar)
t = -7 : 0.1 : 7;

% ecuatiile parametrice ale curbei
x = log(t.^2 + 2);
y = t .* sin(t);
z = -t - 1;

% plot3(x,y,z,'r')
% grid
% xlabel('x');
% ylabel('y');
% zlabel('z');

comet3(x,y,z,0.5)



