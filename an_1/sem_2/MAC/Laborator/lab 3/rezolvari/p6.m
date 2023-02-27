clear
clc
close all
teta=0:0.01:2*pi;
R=6;xc=1;yc=1;
%ecuații parametrice cerc
x=xc+R*cos(teta);
y=yc+R*sin(teta);
plot(x,y)
hold on
clear x;
clear y;
xc=4;yc=1;a=4;b=2;
%ecuații parametrice elipsă
x=xc+a*cos(teta);
y=yc+b*sin(teta);
plot(x,y)
hold off
