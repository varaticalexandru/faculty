clc
clear
close all

x = -2:1:6;

f1 = 1./(sin(x)+2);
f2 = cos(x)./exp(x/2);

plot(x,f1,'b-')
hold on
plot(x,f2,'r-')
hold off

title("Grafice 2D")
xlabel('x')
ylabel('y')
grid minor