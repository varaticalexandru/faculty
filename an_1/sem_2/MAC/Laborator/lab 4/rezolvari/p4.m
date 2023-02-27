A=[-6 8 -1;2 -3 0];
B=[1;-5];
syms x y z;
test=0;
[l c]=size(A);
if(rank(A)~=rank([A B]))
    disp('Sitem incompatibil')
elseif rank(A)==c
    disp('Sistem compatibil determinat')
    sol=pinv(A)*B
    sol=A\B
else
    disp('Sistem compatibil nedeterminat')
disp('rangul matricei A este=');
disp(rank(A))
for i=1:c-1
    for j=i+1:c
    minor=A(:,[i j])
    if det(minor)~=0
        test=1;
        break
    end
    end
    if test==1
        break
    
    end
end
    if test==1
       if i==1 && j==2 alfa=z; k=3; clear x y; 
       elseif i==2 && j==3 alfa=x; k=1; clear y x;
       else alfa =y; k=2; clear x z; 
       end
    bredus=B-alfa*A(:,k);
    sol=pinv(minor)*bredus
    sol=minor\bredus
    end
end