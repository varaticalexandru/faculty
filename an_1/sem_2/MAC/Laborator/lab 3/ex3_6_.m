clear
clc
close all

% elipsoid

% xc,xy,xz - centrul elipsoidului
% rz,ry,rz - lungimile semiaxelor
% n        - number of faces

n = 30;

% precizarea coord. centrului
xc = 3;
yc = -1;
zc = 0;

% precizarea coord. lungimilor semiaxelor
rx = 5;
ry = 3;
rz = 2;

% reprezentarea grafica cu functia elipsoid
ellipsoid(xc,yc,zc,rx,ry,rz,n);
axis('equal');
colormap('spring');
pause

% reprezentarea grafica cu functia sphere
[x,y,z] = sphere(n);
xe = 5*x + 3;
ye = 3*y - 1;
ze = 2*z;
surf(xe,ye,ze);
axis('equal');
colormap('cool');







