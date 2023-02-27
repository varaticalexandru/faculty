%script
v=[2 -1 3];
w=[0 3 -2];
%norme euclidiene
n_v=norm(v)
n_w=norm(w)
pv=cross(v,w)
%acos returneazã unghiul în radiani 
unghi=180/pi*acos(dot(v,w)/(n_w*n_w))
