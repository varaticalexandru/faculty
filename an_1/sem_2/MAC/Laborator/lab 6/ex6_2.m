clear
clc
close all

clc
clear
close all

f = @f6_2;

a = -0.5;
b = 0.5;
x = a : 0.1 : b;

% daca exista o singura solutie (zero) pe interval
if f(a)*f(b) < 0
    options = optimset('TolX', 10^(-10));
    [x fval exitflag output] = fzero(f,[a b],options);
else
    xline(0);
    yline(0);6
    hold on;
    plot(x,(x-1).^4 - tan(x));
    
    [x0 y0] = ginput;
    close all
    
    options = optimset('TolX', 10^(-10));
    [x fval exitflag output] = fzero(f,x0,options);
end


disp('Solutia ecuatiei transcendente: ')
x






% x