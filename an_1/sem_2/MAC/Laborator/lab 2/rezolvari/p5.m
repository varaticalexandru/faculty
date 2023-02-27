%functie
function p5(M)
[l c]=size(M);
if(l~=c)
    disp('Matrice nu este patratica!')
    return
end
disp('M''=')
disp(M')
disp('rangul=')
disp(rank(M))
disp('det(M)=')
disp(det(M))
