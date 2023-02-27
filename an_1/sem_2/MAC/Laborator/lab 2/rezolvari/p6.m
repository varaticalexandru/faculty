%functie
function [determinant, inversa] =p6(M)
[l c]=size(M);
if(l~=c || det(M)==0)
    determinant=[]; inversa=[];
    disp('Matrice nu este patratica sau este singulara!')
    return
end
determinant=det(M);
inversa=inv(M);

