function sol_c = p53(coef)

sol = [];
sol_c = [];

sol = roots(coef);

for i=1:length(sol)
    if ~isreal(sol(i))
        sol_c = [sol_c sol(i)];
    end
end

end