clear
clc
close all

A = [1 -1; 3 2];

% valorile proprii ale matricii A
[vec val] = eig(A);
disp('Valorile proprii ale A:')
diag(val)

% cati vect. proprii corespunde fiecarei val. proprii determinate?
% rs: o infinitate

disp('Vectorii proprii unitari corespunz. val. proprii:')
v1 = vec(1)
v2 = vec(2)
v3 = vec(3)

