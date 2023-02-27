clear
clc
close all

% se creeaza obiecte simbolice
m = sym('m'); n = sym('n'); q = sym('q');

% matricea sistemului
A = [m 0 -n; n -m 0; 0 m m]

% vect. coloana al termenilor liberi
b = [q;0; 2*q]

% ** Discutie ** 
% determinantul sistemului
d = det(A)  % d = -m^3-n^2*m
factor(d)   %  -m*(m^2+n^2)

% d==0 d.n.d. m==0

% cazul d ~= 0 => sis. comp. determinat
disp('Cazul: m~=0 -> sistem compaatibil determinat')

% sol. calc. cu met. inv. matric.
s = inv(A) * b
% sol. calc. cu met. impartirii la st.
ss = A \ b

disp(blanks(2)')
pause

% cazul d==0

% subst. m=0
A = subs(A,m,0)

% ultima linie A: doar '0'
% ultimul elem. q : 2*q =>
% daca q~=0 => sis. incompatibil
% daca q==0 => sis. compatibil nedeterminat

disp('Cazul: m==0, q~=0 -> sis. incompatibil')
disp(blanks(2)')
pause

disp('Cazul: m==0,n~=0,q==0 -> sis. compatibil nedeterminat')
% subst. q=0
b = subs(b,q,0)

% sis. devine
% -n*z == 0; 
% m*x == 0;

% m=0 => n~=0
disp('Solutia: (0,y,0) cu y real oarecare')


