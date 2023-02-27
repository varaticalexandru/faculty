%script
M=zeros(4,4);A=zeros(4,5);
for i=1:4
    for j=1:4
        M(i,j)=i*j/(i+j-1);
    end
end
for i=1:4
    for j=1:5
        if i==j
            A(i,j)=3;
        elseif abs(i-j)==2
                A(i,j)=-3;
        elseif i+j==3
                    A(i,j)=1;
        else
                    A(i,j)=0;
        end
    end
end
M
A
%script
clear; clc;
v1=[2 3 4 1 9 2 -1 -3 5];p=1;i=1;
while( i<=length(v1)&& v1(i)>0)
    p=p*v1(i);
    i=i+1;
end
p
v2=[2 3 4 1 9 2 1 3 5];p=1;i=1;
%de avut în vedere ordinea în care se evalueaza expresiile din bucla while
while(i<=length(v1) && v2(i)>0 )
    p=p*v2(i);
    i=i+1;
end
p    
    
    
    