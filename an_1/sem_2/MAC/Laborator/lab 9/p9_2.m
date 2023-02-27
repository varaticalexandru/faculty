clear
clc
close all

% metoda lui Simpson

a = pi/3; 
b = pi/2;
f = @f9_2a;

disp('Valoarea integralei definite:')
I = quad(f, a, b)