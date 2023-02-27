clc
clear

v = [2 , 1, 3]
w = [0, 3, -2]

n_v = norm(v)
n_w = norm(w)

ps = dot(v,w)
pv = cross(v,w)

unghi = 180/pi * acos(ps/(n_v*n_w))
