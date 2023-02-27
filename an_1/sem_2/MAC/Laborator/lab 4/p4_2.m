clear
clc
close all

A = [4 3 -1; -1 1 1; 1 0 3; 4 4 3];
b = [2; 0; -1; 1];

[sol x] = sys(A,b)
rankA = rank(A)

pause
clear
clc

A = [-6 8 -1; 2 -3 0];
b = [-5; 7];

[sol x] = sys(A,b)
rankA = rank(A)
