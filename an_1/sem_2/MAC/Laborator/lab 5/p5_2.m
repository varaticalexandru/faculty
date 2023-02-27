clear
clc
close all

coef = [3 1 1 1];


sol_r = sol_r(coef);
if isempty(sol_r)
    disp('Ecuatia nu are solutii reale')
else
    disp('Solutiile reale ale ecuatiei: ')
    sol_r
end