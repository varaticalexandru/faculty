clear
clc
close all

x = -8:0.2:8;
y = x;
[x y] = meshgrid(x,y);

R = sqrt(x.^2 + y.^2);
S = sin(R);
[i,j] = find(R==0);
R(i,j)=1;
S(i,j)=1;
z = S./R;

surfl(x,y,z)
xlabel('x')
ylabel('y')
zlabel('z')

shading interp
colormap("flag")