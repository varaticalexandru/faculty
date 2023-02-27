function sol=p3(A,b)
[m,n]=size(A); b=b(:);
k=length(b);
if m~=k
disp('dimensiuni necorespunzatoare')
sol=[];
end
return
end
if rank(A)==rank([A b])
if rank(A)==n
sol=A\b;
else
sol='sistem compatibil nedeterminat';
end
else
sol='sistem incompatibil';
end
