clear
clc
close all

v = [2, -1, 3]
w = [0, 3, -2]

% normele euclidiene
nv = norm(v)
nw = norm(w)

% produsul scalar
ps = dot(v, w)

% cos unghiului dintre v si w
cos_unghi = ps/(nv*nw)

% unghi dintre v si w (in grade)
unghi = acosd(cos_unghi)




