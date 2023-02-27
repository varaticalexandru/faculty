clear
clc
close all

% metoda lui Simpson

a = 0;
b = pi;
f = @f9_2;

disp('Valoarea integralei definite: ');
I = quad(f,a,b)