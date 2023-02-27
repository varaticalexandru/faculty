clear
clc

% valorile proprii
% vectori proprii + valori proprii

A = [1 3; -1 2];
val_p = eig(A)
[vect_p, val_p] = eig(A)