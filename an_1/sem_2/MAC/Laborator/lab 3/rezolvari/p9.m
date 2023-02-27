clear;clc;close all
h=3;rc1=2;rc2=1;rp=3;
[x,y,z]=cylinder([rc1 rc2],100);
z=z*h;
figure
surf(x,y,z);
disp('Apasati o tasta')
pause
[x,y,z]=cylinder([rp 0],6);
z=z*h;
figure
surf(x,y,z);