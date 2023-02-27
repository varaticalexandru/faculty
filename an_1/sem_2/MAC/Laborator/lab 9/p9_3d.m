clear
clc
close all


%{
    Sis. ec. dif.
    x' + 2x = y - 2z + sin(t)
    y' + 2y = x + 2z
    z' - 5z = 33x - 3y

    x' = y - 2z + sin(t) - 2x
    y' = x + 2z - 2y
    z' = 33x - 3y + 5z

    x(0) = 0
    y(0) = 0.2
    z(0) = -0.1

    pe [0, 3]
%}

f = @f9_3d;
p0 = [0; 0.2; -0.1];
dom = [0 3];
xval = [];
yval = [];

[xval yval] = ode113(f, dom, p0)

plot(xval, yval(:,1));
hold on
grid
xline(0)
yline(0)
plot(xval, yval(:,2),'--');
plot(xval, yval(:,3),'-.');
legend('x','y','z');
hold off

vx = [0, 0.75, 1.1, 1.16, 2, 3];
x = xval
y = yval(:,1)

vy = interp1(x, y, vx, "pchip")
vy = interp1(x, y, vx, "spline")
vy = interp1(x, y, vx, "linear")


p2 = polyfit(x, y, 2);
vy_p2 = polyval(p2, vx)

p3 = polyfit(x, y, 3);
vy_p3 = polyval(p3, vx)
