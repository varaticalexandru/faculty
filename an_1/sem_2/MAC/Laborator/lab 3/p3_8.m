clear
clc
close all

% z(x,y) = x^3 -3xy^2

x = -3 : 0.1 : 3;
y = -3 : 0.1 : 3;

[X Y] = meshgrid(x,y);

Z = X.^3 - 3.*X.*Y.^2;

plot3(X,Y,Z);
pause;
disp('Apasati o tasta ...')

mesh(X,Y,Z);
pause;
disp('Apasati o tasta ...')

surf(X,Y,Z);
pause;
disp('Apasati o tasta ...')

surfl(X,Y,Z);