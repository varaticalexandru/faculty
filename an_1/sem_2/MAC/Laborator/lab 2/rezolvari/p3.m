function p3(M)
[l c]=size(M);
if(l<4 || c<4)
    disp('Dimensiune matrice incorecta!')
    return
end
M(3,:)
M(:,end)
M(end,:)
M(2:4,1:3)
end
%{
- ex:initializarea lui M si apel din linia de comandã
M=[1 2 3 4 5;6 7 8 9 10;1 2 3 4 5 ;6 7 8 9 11]
M =
     1     2     3     4     5
     6     7     8     9    10
     1     2     3     4     5
     6     7     8     9    11
p3(M)
%}