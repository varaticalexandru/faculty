clear
clc
close all

A = [13 -10 12; -11 14 10; 0 12 -13];

% val. proprii (A)
[vec val] = eig(A);
disp('Valorile proprii ale matricei A:')
val = diag(val)

% Vectorii proprii unitari coresp. valorilor proprii
disp('Vectorii proprii unitari coresp. valorilor proprii:')
v1 = vec(:,1)
v2 = vec(:,2)
v3 = vec(:,3)

% valorile singulare
% [U S V] = svd(A)
disp('Valorile singulare:')
sing = svd(A)

% nr. de conditionare in raport cu inversarea matricei A
ncond = cond(A)
ncondcompl = rcond(A)
