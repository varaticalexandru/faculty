clear
clc
close all

% piramida

% rc -  raza cerc. circum. bazei
% h -  inaltimea piramizii
% nr - lat. bazei

rc = 1.25;
h = 3;
n = 8;

% det. coord. supr. piramidei de h=1
[Xp Yp Zp] = cylinder([rc 0],n);

% stabilirea h
Zp = Zp * 3;

% reprezentarea grafica
surf(Xp,Yp,Zp)
colormap('lines');
axis('equal');


xlabel('x')
ylabel('y')
zlabel('z')
title('Piramida')










