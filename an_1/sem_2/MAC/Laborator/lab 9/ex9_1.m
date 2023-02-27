clear
clc
close all

% metoda trapezelor

x = [];
y = [];

for i = 1 : 150
    x(i) = pi + i*pi/30;
    y(i) = sin(x(i))/(i^2+1) * cos(i/x(i));
end

disp('Valoarea integralei definite: ');
I = trapz(x,y)