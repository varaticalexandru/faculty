function p5(A,b)
[l c]=size(A);
if(l~=length(b))
    disp('Dimensiuni necorespunzãtoare')
    return
end
if rank(A)==rank([A,b])
    if rank(A)==c
        disp('Sistem compatibil determinat')
    else
        disp('Sistem compatibil nedeterminat')
    end
else
    disp('Sistem incompatibil')
end
        