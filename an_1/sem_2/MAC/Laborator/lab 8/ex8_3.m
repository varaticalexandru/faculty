clear
clc
close all


x = [-8 -6 -4 -2 0 2 4];
y = [30 10 9 6 5 4 4];

%{
  sa se aprox. in sensul CMMP functia f in punctele
  -7, -4.2, -0.75, 1, 2.15, 3 folosind:
  regresia parabolica
  regresia cubica
  regresia cu polinom de gr.6
%}

vx = [-7 -4.2 -0.75 1 2.15 3];

% regresia parabolica
p2 = polyfit(x,y,2);
vy_p2 = polyval(p2,vx)

% regresia cubica
p3 = polyfit(x,y,3);
vy_p3 = polyval(p3,vx)

% regresia cu polinom de gr.6
p6 = polyfit(x,y,6);
vy_p6 = polyval(p6,vx)

vxg = min(x) : (max(x)-min(x))/100 : max(x);
vy_p2_g = polyval(p2,vxg);
vy_p3_g = polyval(p3,vxg);
vy_p6_g = polyval(p6,vxg);

plot(x,y,'bd');
hold on
grid
xline(0);
yline(0);
plot(vxg,vy_p2_g,'r-.');
plot(vxg,vy_p3_g,'k--');
plot(vxg,vy_p6_g,'k:');
legend('puncte','regresie parabolica','regresie cubica','regresie grad 6');
hold off