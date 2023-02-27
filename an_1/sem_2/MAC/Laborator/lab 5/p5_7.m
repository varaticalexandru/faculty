clear
clc
close all

A = [2 -3 0; -6 8 -1; 0 3 4];
nrcc = rcond(A)
disp('rcond(A) -> 0')
disp('Concluzie: sistemul este slab conditionat')

B = [190 7; 2 200];
nrcc = rcond(B)
disp('rcond(B) -> 1')
disp('Concluzie: sistemul este bine conditionat')
