clear
clc
close all

t1 = -9 : 0.1 : -3+0.1;
t2 = 3 : 0.1 : 9;
t3 = -3 : 0.1 : 3-0.1;

y1 = sin(5*t1);
y2 = sin(5*t2);
y3 = cos(t3) - cos(3) - sin(15);


plot(t1,y1, t3,y3, t2,y2);
xlabel('x');
ylabel('y');
title('Titlu');

