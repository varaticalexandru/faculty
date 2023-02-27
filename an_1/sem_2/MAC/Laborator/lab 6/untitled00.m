clc
clear
close all

% % 6.1 a
% x0 = 1;
% 
% f = @f6_1_a;
% x = -10 : 0.05 : 10;
% 
% plot(x,x.^2 - 3 - sin(x) - sqrt(abs(x)));
% xline(0); yline(0);
% axis([-5 5 -5 5])
% 
% options = optimset('TolX', 10^(-10));
% [x_sol fval exitflag output] = fzero(f,x0,options);
% disp('Solutia ecuatiei transcendente: ')
% x_sol



% % 6.1 b
% f = @f6_1_b;
% x0 = -3;
% x = 0 : 0.05 : 5;
% 
% options = optimset('TolX', 10^(-6));
% [x fval exitflag output] = fzero(f,x0,options);
% 
% disp('Solutia ecuatiei transcendente in vecinatatea x0 = -3:')
% x
% disp('Numarul de iteratii efectuate:')
% disp(output.iterations)



% % 6.1 b
% f = @f6_1_b;
% x = -3 : 0.05 : 0;
% 
% g = exp(-x.^2);
% h = log(1-x+((x.^2)/3));
% 
% plot(x,g,'b-', x,h,'r:');
% xline(0); yline(0);
% [x0 y0] = ginput;
% close all;
% 
% options = optimset('TolX', 10^(-6));
% [x_sol fval exitflag output] = fzero(f,x0,options);
% 
% disp('Solutia ecuatiei transcendente in vecinatatea x0 = -3:')
% x_sol
% disp('Numarul de iteratii efectuate:')
% disp(output.iterations)



% % 6.1 c
% a = 3.1;
% b = 5;
% f = @f6_1_c;
% x = 3.1 : 0.05 : 5;
% x_sol = [];
% 
% options = optimset('TolX', 10^(-10));
% plot(x, 2.^-sin(x) + 4 - x.*log(x)); 
% xline(0); yline(0);
% 
% if f(a)*f(b)<0
%     [x_sol fval exitflag output] = fzero(f,[a b],options);
% else
%     [x0 y0] = ginput;
%     for i = 1 : numel(x0)
%         x_sol(i) = fzero(f,x0(i),options);
%     end
% end
%  
% disp('Solutia ecuatiei transcendente:')
% x_sol



% % 6.2
% x = -5 : 0.05 : 5;
% g = exp(cos(x));
% h = sin(x) + 1;
% f = 'exp(cos(x)) - sin(x) - 1';
% f1 = g - h;
% 
% plot(x,f1);
% xline(0);
% yline(0);
% 
% [x0 y0] = ginput;
% close all;
% 
% options = optimset('TolX', 10^(-10));
% for i = 1 : numel(x0)
%     x_sol(i) = fzero(f,x0(i),options);
% end
% 
% disp('Solutiile ecuatiei transcendente:')
% x_sol



% % 6.3
% syms a b x p;
% 
% eq = 2*b*(cos(x)^2) + 2*a*sin(x)*cos(x) - p*sqrt(a^2+b^2) - b;
% simplify(solve(eq,x))


