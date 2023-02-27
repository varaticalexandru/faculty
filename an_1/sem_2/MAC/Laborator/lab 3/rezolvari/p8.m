clear;clc;close all;
x=-3:0.2:3;
y=-3:0.2:3;
[x y]=meshgrid(x,y);
z=x.^2-3*x.*y.^2;
figure
plot3(x,y,z)
disp('Apasati o tasta');
pause
figure
surf(x,y,z)
disp('Apasati o tasta');
pause
figure
surfl(x,y,z)
disp('Apasati o tasta');
pause
figure
mesh(x,y,z)

