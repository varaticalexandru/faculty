clear
clc
close all

% spirala 3D

t = -10*pi : pi/10 : 10*pi;

x = t;
y = sin(0.5*t-3);
z = cos(0.5*t);

% plot3(x,y,z,'r-', 'LineWidth',0.9);
comet3(x,y,z,0.9);
grid;

xlabel('x');
ylabel('y');
zlabel('z');

title('Spirala 3D');