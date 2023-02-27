function sol_su = sol_su(coef)
    sol_su = [];
    % sol. complexe de modul supraunitar
    sol = roots(coef);
    sol_su = sol(abs(sol)>1);
end