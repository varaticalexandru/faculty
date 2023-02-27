clear
clc
close all

% matricea sis. , sol. exacta , vect. term. liberi
A = rand(700);
x = rand(700,1);
b = A * x;

% timpi de executie
tic; y=inv(A)*b; timp1 = toc
tic; z =A\b; timp2 = toc

% precizia sol. calc.
n1 = norm(A*y-b)
n2 = norm(A*z-b)
n1/n2

disp('timp1 > timp2')
disp('n1 > n2')
disp('Concluzie: metoda impartirii la stanga - precizie si viteza mai buna')