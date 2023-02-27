clear
clc
close all

% sa se calc. integrala din f(x) dx

% metoda trapezelor

x = [];
y = [];

for j = 1 : 11
    x(j) = -1.1 + 0.1*j;
    y(j) = j*x(j)^2/(x(j)-1) - 2/(j+1);
end

disp('Valoarea integralei definite:')
I = trapz(x,y)