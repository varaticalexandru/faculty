function [l3, uc, ul, subm] = extrage(A)
l3 = []; uc = []; ul = []; subm = [];

[r c] = size(A);
if r<4 | c<4
    disp('Nr. minim de randuri si coloane trebuie sa fie 4!')
    return
end

l3 = A(3,:)
uc = A(:,c)
ul = A(r,:)
subm = A([2:4],[1:3])

end