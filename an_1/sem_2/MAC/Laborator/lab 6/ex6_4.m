clear
clc
close all

% syms a b u v;
% 
% f = a*cos(u-v) + b*sin(u+v);
% sol_u = simplify(solve(f,u))


% definirea obiectelor simbolice 
syms a b u v; 
% definirea membrului stang al ecuatiei scrisa sub forma 
% f(x)=0 
f=a*cos(u-v)+b*sin(u+v); 
% rezolvarea ecuatiei in cazul cel mai favorabil 
solu=simplify(solve(f,u))

ff=expand(f); 
 
% (a) sin(v)=sqrt(2)/2, cos(v)=sqrt(2)/2 
ffa=subs(ff,sin(v),sqrt(2)/2); 
ffa=subs(ffa,cos(v),sqrt(2)/2); 
solu_a=solve(ffa,u) 
 
% (b) sin(v)=sqrt(2)/2, cos(v)=-sqrt(2)/2 
ffb=subs(ff,sin(v),sqrt(2)/2); 
ffb=subs(ffb,cos(v),-sqrt(2)/2); 
solu_b=solve(ffb,u) 
 
% (c) sin(v)=-sqrt(2)/2, cos(v)=-sqrt(2)/2 
ffc=subs(ff,sin(v),-sqrt(2)/2); 
ffc=subs(ffc,cos(v),-sqrt(2)/2); 
solu_c=solve(ffc,u) 
 
% (d) sin(v)=-sqrt(2)/2, cos(v)=sqrt(2)/2 
ffd=subs(ff,sin(v),-sqrt(2)/2); 
ffd=subs(ffd,cos(v),sqrt(2)/2); 
solu_d=solve(ffd,u) 