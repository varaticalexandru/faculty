function RepHex(p)
if p<=0
    return
end
culori=["red", "blue", "black"];
X=[0 2 2;   0 2 0;     0 0 -2;  0 -2 -2 ; -2 0 0;0 2 0];
Y=[0 -1 1;  0 1 2;     0 2 1;   0 1  -1; -1 0 -2;-2 -1 0];
r=mod(p,3)+1;
j=r;
for i=1:6
    fill(X(i,:),Y(i,:),culori(j));
    hold on
    j=j-1;
    if(j==0)
        j=r;
    end
end
hold off
end