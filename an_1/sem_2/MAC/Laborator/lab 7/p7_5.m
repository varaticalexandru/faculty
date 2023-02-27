clear
clc
close all

% sa se determine toate (a,b,c):
% a) a,b,c - pr.geom.
% b) a, b+4, c - pr.aritm
% c) a, b+4, c+32 - pr.geom.

% Sistemul format:
% a * c = b^2
% a + c = 2*(b+4)
% a * (c+32) = (b+4)^2

% Sistemul canonic:
% a*c - b^2 = 0
% a + c - 2*(b+4) = 0
% a * (c+32) - (b+4)^2 = 0

syms a b c;

eq1 = a*c - b^2;
eq2 = a + c - 2*(b+4);
eq3 = a * (c+32) - (b+4)^2;

sol = solve(eq1,eq2,eq3, a,b,c);
fprintf('Solutiile sistemului de ecuatii neliniare:\n');

for i = 1 : length(sol.a)
    fprintf('[%g %g %g]\n', sol.a(i),sol.b(i),sol.c(i))
end