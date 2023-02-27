clc
clear

M=[]; 

for i=1:4
    for j=1:4
        M(i,j) = i*j/(i+j-1);
    end
end

M