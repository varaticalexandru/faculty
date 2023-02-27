%a
clear
clc
t1=-9:0.1:-3+0.1;
t2=-3:0.1:3-0.1;
t3=3:0.1:9;
y1=sin(5*t1);
y2=cos(t2)-cos(3)-sin(15);
y3=sin(5*t3);
t=[t1 t2 t3];
y=[y1 y2 y3];
figure
plot(t,y)
%b
clear 
clc
t=-3:0.1:3;
f=sin(pi*t).*cos(pi*t);
g=sin(pi*t+1).*cos(pi*t+1);
figure
plot(t,f,'m--',t,g,'cs-')