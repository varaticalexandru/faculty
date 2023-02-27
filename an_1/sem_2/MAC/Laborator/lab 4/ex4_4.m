clc
clear
% pas 1: se determina rangul matricei sistemului
A=[3 -1 1 -2;-4 4 2 1]; 
r=rank(A) % se obtine 2
% prin urmare, 2 variabile sunt independente, si 2 
% variabile sunt dependente de primele
 
% pas 2: se cauta un minor de ordinul 2 nenul, pentru a 
% stabili variabilele dependente; de exemplu:
rminor=rank(A(:,[1 2])) % se obtine 2
% x,y devin variabilele dependente, in raport cu care se
% rezolva sistemul;
% acesta se rescrie sub forma: 
% 3x-y=6-z+2t; -4x+4y=-2z-t;
 
disp('sistemul este compatibil nedeterminat') 
disp(blanks(1)') 
 
% pas 3: se rezolva sistemul rescris in noua forma:
% se creeaza obiectele simbolice
syms z t; 
% matricea sistemului
Aredus=A(:,[1 2]); 
% vectorul termenilor liberi
bredus=[6-z+2*t; -2*z-t]; 
% rezolvarea sistemului cu metoda inversarii
s=inv(Aredus)*bredus 
% rezolvarea sistemului cu operatorul de impartire la 
% stanga
ss=Aredus\bredus 
disp(blanks(1)') 
pause 
disp('Solutia sistemului dat este:') 
x=s(1) 
y=s(2) 
disp('z,t numere reale oarecare')