clear
close all
clc

% sa se determine punctul de min. situat in vecin. x0 = 0.5 si minimul
% unconstrained (fminsearch/fminunc)

f = @f7_6a;
x0 = 0.5;
x = -5 : 0.05 : 5;

[xmin fmin exitflag output] = fminunc(f,x0);
fprintf('Punctul de minim in vecin. x0 = 0.5: %g\nMinim: %g\n', xmin, fmin);

plot(x, log(1 - x + (x.^2)./3));
grid
xline(0);
yline(0);
pause
close all