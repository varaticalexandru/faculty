clc
clear

% rezolvati ec. alg. in R
% ec: x^4 + 2x^3 + 6x^2 + 4x + 5 = 0

coef = [1 2 6 4 5];

sol = roots(coef);
sol_R = ec(coef);

if (isempty(sol_R))
    disp("Nu exista solutii reale !")
    sol
else
    disp("Solutiile reale :")
    sol_R
end
