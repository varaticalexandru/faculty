function [nv,nw,ps,pv,unghi] = f2_3(v, w)
if length(v)~=3 | length(w)~=3
    disp('Vectorii nu satisfac conditia de lungime 3!')
    nv=[];nw=[];ps=[];pv=[];unghi=[];
    return;
end

nv = norm(v);
nw = norm(w);
%nv = norm(v, 2); nw = norm(w, 2);
ps = dot(v,w);
pv = cross(v,w);

if nv==0 | nw == 0
    disp("Unghiul nu poate fi calculat, unul din vectori fiind 0.")
    unghi=[];
else
    unghi = acos(ps/(nv*nw));
end

end