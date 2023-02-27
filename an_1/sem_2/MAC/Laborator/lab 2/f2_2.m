function [v,len_v,sum_v] = f2_2(a,b,p)
v=[]; len_v=[]; sum_v=[];

v = a:p:b
len_v = length(v)

if len_v > 0
    sum_v = sum(v);
else
    sum_v = [];
end

sum_v

end