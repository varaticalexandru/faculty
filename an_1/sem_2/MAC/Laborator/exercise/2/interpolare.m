clear
clc
close all


x = [-3 -2 -1 0 1 2 3];
y = [4 1 0 1 4 9 16];

vx = [-1.5 1.5 2.5]

%% interpolare
vy_linear = interp1(x,y,vx,"linear")
vy_cubic = interp1(x,y,vx,"cubic")
vy_spline = interp1(x,y,vx,"spline")

%% regresie (CMMP)
p = polyfit(x, y, 3);
vy = polyval(p, vx)

