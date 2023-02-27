clear
clc
close all

% sa se rezolve prob. de optimizare fara restrictii (unconstrained)
% metoda de cautare "Nelder-Mead simplex direct search"

f = @f7_8;
v0 = [0; 0];

[xmin fmin exitflag output] = fminsearch(f,v0);
fprintf('Punctul de minim: [%g %g]\n', xmin);
fprintf('Minimul: %g\n', fmin);
fprintf('Metoda de optimizare: %s\n', output.algorithm);
