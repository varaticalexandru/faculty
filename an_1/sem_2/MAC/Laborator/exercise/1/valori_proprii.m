clear
clc
close all

A = [13 -10 12; -11 14 10; 0 12 -13];

% valori proprii
lambda = eig(A)

% cate un vector unitar pt fiecare val. proprie
[vec val] = eig(A);

disp('vectori proprii unitari corespunzatori val. pr.')
for i = 1 : 3
    disp(vec(:,i))
end

% valori singulare
disp('valori singulare')
disp(svd(A))

% nr. de conditioare
cond = cond(A)
rcond = rcond(A)
