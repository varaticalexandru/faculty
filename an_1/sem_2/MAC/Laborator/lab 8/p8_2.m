clear
clc
close all

% sa se estimeze val. vitezei la momentele
% t1 = 0.5 s
% t2 = 3.2 s
% t3 = 5.7 s
% a) interpolare liniara
% b) interpolare Lagrange
% c) interpolare cu polinom Hermite cubic pe portiuni
% d) interpolare spline cubica
% e) regresie parabolica
% f) aproximarea cu metoda CMMP cu polinom de gr. 5

x = 0 : 1 : 6;                  % timp(s)
y = [15 30 75 60 60 40 55];     % viteza(m/s)
vx = [0.5 3.2 5.7];

% interpolare liniara
vy_linear = interp1(x,y,vx,"linear")

% interpolare polinomiala Lagrange
vy_lagrange = LagrangeInterp(x,y,vx)

% interpolare cu polinom Hermite cubic pe portiuni
vy_hermite = interp1(x,y,vx,"cubic")

% interpolare spline cubica
vy_spline = interp1(x,y,vx,"spline")

% regresie parabolica
p2 = polyfit(x,y,2);
vy_p2 = polyval(p2,vx)

% CMMP de grad 5
p5 = polyfit(x,y,5);
vy_p5 = polyval(p5,vx)


vxg = min(x) : (max(x)-min(x))/100 : max(x);
vy_linear_g = interp1(x,y,vxg,"linear");
vy_lagrange_g = LagrangeInterp(x,y,vxg);
vy_hermite_g = interp1(x,y,vxg,"cubic");
vy_spline_g = interp1(x,y,vxg,"spline");
vy_p2_g = polyval(p2,vxg);
vy_p5_g = polyval(p5,vxg);


plot(x,y,'bd');
hold on
xline(0);
yline(0);
grid;
plot(vxg,vy_linear_g,'r--');
plot(vxg,vy_lagrange_g,'m:');
plot(vxg,vy_hermite_g,'r:');
plot(vxg,vy_spline_g,'c--');
plot(vxg,vy_p2_g,'k-');
plot(vxg,vy_p5_g,'g--');
hold off