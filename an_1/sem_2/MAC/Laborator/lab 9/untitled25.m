clear
clc
close all

I = trapz(x,y);
I = quad(f,a,b,precision);

ode23 % Runge-Kutta
ode45 % Runge-Kutta 
ode113 % Adams-Bashforth-Moulton

[xval yval] = ode23(f,dom,y0)
