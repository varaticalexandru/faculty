clc
clear

% setarea preciziei de calcul
options = optimset('Tolx', 10^(-10));

% calcularea solutiei
[x, fval, exitflag, output] = fzero('ectrans1', -0.5, options);

% solutia
x

% numarul de iteratii
iter = output.iterations
