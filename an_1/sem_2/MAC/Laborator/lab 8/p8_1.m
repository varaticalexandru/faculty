clear
clc
close all

x = 0 : 1 : 10
y = x.^2
xx = linspace(0,10);
yy = LagrangeInterp(x,y,xx);
plot(x,y,'bd');
hold on
grid
xline(0)
yline(0)
plot(xx,yy,'r-.')
hold off