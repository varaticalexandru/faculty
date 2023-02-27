clear
clc
close all

% sa se determine o solutie a sis. de ec. neliniare
% sin(x+y) - 1.1x = 0.2
% 1.1x^2 + 2y^2 = 1
% pornind de la aprox. init. x0 = 1, y0 = 1

f = @f7_1a;
v0 = [1; 1];

% metoda numerica
[x fval exitflag output] = fsolve(f,v0);

fprintf('Solutia sistemului de ecuatii neliniare :\n[%g %g]\n',x);
