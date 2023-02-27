clear
clc
close all

% sa se determine pe cale numerica toate solutiile sis. de ec. neliniare

% x^2 + y^2 = 4
% x - y = 1

f = @f7_2a;

% cerc de raza 2
r = 2;
theta = 0 : pi/60 : 2*pi;
x = r*cos(theta);
y = r*sin(theta);
hold on
plot(x,y);
axis equal
grid

% y = x - 1 (ec. gr. 1)
x1 = -3 : 0.05 : 3;
y1 = x1 - 1;
plot(x1,y1);
hold off

[xcoord ycoord] = ginput;
close all

for i = 1 : length(xcoord)
    sol (i,:) = fsolve(f,[xcoord(i), ycoord(i)]);
end

fprintf('Solutiile sistemului de ecuatii neliniare:\n[%g %g]\n[%g %g]\n', ...
    sol(1,:), sol(2,:));


