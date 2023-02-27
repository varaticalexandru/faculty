function sol_r = sol_r(coef)
    sol_r = [];
    sol = roots(coef);
    sol_r = sol(imag(sol)==0);
end