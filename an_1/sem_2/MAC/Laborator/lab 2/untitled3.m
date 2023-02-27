clc
clear

M = [];

for i=1:4
    for i=1:5
        if (i ==j) M(i,j) = 3;
        elseif (abs(i-j) == 2) M(i,j) = -3;
        elseif (i + j == 3) M(i,j) = 1;
        else M(i,j) = 0;
        end
    end
end

M;