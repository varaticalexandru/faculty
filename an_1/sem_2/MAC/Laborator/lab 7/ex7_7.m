clear
clc
close all

% sa rezolve problema de optimizare fara restrictii (unconstrained)
% metode quasi-Newton (fminunc)

v0 = [1;0;-1];
f = @f7_7;

options = optimset('LargeScale', 'off');
[xmin fmin exitflag output] = fminunc(f,v0,options);

fprintf('Punctul de minim: [%g %g %g]\n', xmin);
fprintf('Minimul: %g\n', fmin);
fprintf('Metoda de optimizare: %s\n', output.algorithm);