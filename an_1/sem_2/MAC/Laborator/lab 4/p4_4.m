clear
clc
close all

A = [-6 8 -1; 2 -3 0];
b = [-5; 7];

% [sol x] = sys(A,b)

rankA = rank(A) ;
% 2 var. indep (x,y)., 1 var depend. (z)
A(:,[1 2]);
rminor = rank(A(:,[1 2]));

z = sym('z');

Aredus = A(:,[1 2]);
bredus = [-5+z; 7];

sol = Aredus \ bredus;
disp('x = ') 
disp(sol(1))
disp('y = ') 
disp(sol(2))
disp('pentru orice z - nr. real')



