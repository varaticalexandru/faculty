clear
clc
close all

% sa se reprezinte in aceeasi fereastra grafica
% functiile de interpolare liniara / spline cubica
% pentru functia f

x = [-1.5 0 1 3];
y = [7.8 5 6.3 6.8];
vx = -1.5 : 0.05 : 3;

vy_linear = interp1(x,y,vx,"linear");
vy_spline = interp1(x,y,vx,"spline");


plot(x,y,'b-o');
hold on
grid;
xline(0);
yline(0);
plot(vx,vy_linear,'r-.');
plot(vx,vy_spline,'k--');
legend('puncte','linear','spline');
hold off




