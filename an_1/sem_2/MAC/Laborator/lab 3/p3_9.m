clear
clc
close all

% trunchi de con
% rc1 = 2, rc2 = 1, h = 3

r = [2 1];
n = 150;
h = 3;
[X,Y,Z] = cylinder(r,n);
Z = Z * h;

surf(X,Y,Z);
colormap('summer');
axis('equal');
title('Trunchi de con')
xlabel('x'); ylabel('y'); zlabel('z');

disp('Apasati o tasta ...')
pause;
close all
clear
clc

% piramida 
% h, baza:hexagon regulat, rp = 3

r = [3,0];
n = 6;
h = 6;
[X Y Z] = cylinder(r,n);
Z = Z*h;

surf(X,Y,Z);
surf(X,Y,Z);
colormap('autumn');
axis('equal');
title('Piramida')
xlabel('x'); ylabel('y'); zlabel('z');





