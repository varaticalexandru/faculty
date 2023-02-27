clear
clc
close all

v1 = [2 3 1 9 2 -1 -3 5]
v2 = [2 3 1 9 2 1 3 5]

i = 1;
pp = 1;

while i <= length(v2) & v2(i) >= 0
    pp = pp * v2(i);
    i = i + 1;
end

pp

