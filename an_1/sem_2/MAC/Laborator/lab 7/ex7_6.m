% clear
% clc
% close all
% 
% % i) sa se det. un punct de minim local din intervalul (-8, 10), 
% %    precum si minimul corespunzator al functiei
% 
% f = @f7_6;
% a = -8;
% b = 10;
% 
% [xmin fval exitflag output] = fminbnd(f,a,b);
% disp('Punctul de minim local:'); disp(xmin);
% disp('Valoarea functiei in punctL '); disp(fval);


% ii) sa se det. toate punctele de extrem local din intervalul (-8, 10),
%     precum si valorile f. in acestea, precizand si tipul de extrem

clear
clc
close all

f = @f7_6;
a = -8;
b = -10;

x = a : 0.05 : b;
plot(x,(x/4).^2 - sin(x) - 0.5);
grid
xline(0);
yline(0);


[xmin1 fmin1] = fminbnd(f,-6,-3);
[xmax1 fmax1] = fminbnd(f,-3,-1);
[xmin2 fmin2] = fminbnd(f,0,3);
[xmax2 fmax2] = fminbnd(f,4,6);
[xmin3 fmin3] = fminbnd(f,6,8);

fprintf('Punct de minim: %g, minimul: %g\n', xmin1,fmin1);
fprintf('Punct de maxim: %g, maximul: %g\n', xmax1,fmax1);
fprintf('Punct de minim: %g, minimul: %g\n', xmin2,fmin2);
fprintf('Punct de maxim: %g, maximul: %g\n', xmax2,fmax2);
fprintf('Punct de minim: %g, minimul: %g\n', xmin3,fmin3);
