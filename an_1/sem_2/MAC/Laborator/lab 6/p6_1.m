clear
clc
close all

% a)
% solutia in vecinatatea valorii x0 = 1
% x = 0 : 0.05 : 3;
% x0 = 1;
% 
% f = x.^2 - 3 - sin(x) - sqrt(abs(x));
% plot(x,f);
% xline(0); 
% yline(0);
% 
% options = optimset('TolX', 10^(-10));
% [sol_x fval exitflag output] = fzero('f6_1_',x0,options);
% disp('Solutia ecuatiei transcendente:')
% sol_x

clear
clc
close all

% b)
% solutia in vecinatatea x0 = 3, cu precizia 10^(-6)
% nr. de iteratii facute

% x = -5 : 0.05 : 5;
% x0 = -3;
% f = 'exp(-(x.^2)) - log(1-x+x.^2/3)';
% g = exp(-(x.^2)) ;
% h = log(1-x+x.^2/3);
% plot(x,g, x,h);
% xline(0)
% yline(0)
% 
% options = optimset('TolX', 10^(-6));
% [sol_x fval exitflag output] = fzero(f, x0, options);
% disp('Solutia ecuatiei transcendente:')
% sol_x
% disp('Numarul de iteratii efectuate:')
% output.iterations


clear
clc
close all

% c)
% solutia in intervalul [3.1, 5]

% x = 3.1 : 0.05 : 5;
% f = '2.^(-sin(x)) - x.*log(x) + 4';
% g = 2.^(-sin(x));
% h = x.*log(x) - 4;
% 
% plot(x,g, x,h);
% options = optimset('TolX', 10^(-10));
% [x_sol fval exitflag output] = fzero(f, [3.1 5], options);
% disp('Solutia ecuatiei transcendente:')
% x_sol


clear
clc
close all

% d)
% solutia in interval la alegere
x = -5 : 0.05 : 5;
f = (x-3).^2 + 5 - cos(abs(x));
g = (x-3).^2 + 5;
h = cos(abs(x));

plot(x,g, x,h)
xline(0)
yline(0)

if (f6_1__(-5)*f6_1__(5) > 0)
    disp('Ecuatia transcendenta nu se anuleaza in nici un punct !')
else
    options = optimset('TolX', 10^(-10))
    [sol_x fval exitflag output] = fzero(f, [-5 5], options);
    disp('Solutia ecuaitiei transcendente:')
    sol_x
end






