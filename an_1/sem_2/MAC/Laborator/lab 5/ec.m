function sol_R = ec(coef)
    sol_R = [];
    sol = [];

    sol = roots(coef);

    for i=1 : length(sol)
        if isreal(sol(i))
            % concatenare
            sol_R = [sol_R, sol(i)];
        end
    end



end