clear
clc
close all

% sa se det. toate p. de extrem local in (-6, 6)
% precum si valorile functiei in aceste puncte
% precizand si tipul de extrem pt. fiecare p.

f = @f7_7a;
a = -6;
b = 6;

x = -6 : 0.05 : 6;

g = @(x) -f(x);

plot(x, sin(x) + sqrt(abs(x)));
grid;
xline(0);
yline(0);

[xmax1 fmax1] = fminbnd(g, -5.4, -4.4);
fmax1 = abs(fmax1);

[xmin1 fmin1] = fminbnd(f,-1.5, -0.5);

[xmax2 fmax2] = fminbnd(g, -0.5, -0.05);
fmax2 = abs(fmax2);

[xmin2 fmin2] = fminbnd(f,-0.05, 0.05);

[xmax3 fmax3] = fminbnd(g, 1.4, 2.2);
fmax3 = abs(fmax3);

[xmin3 fmin3] = fminbnd(f,4, 5);
