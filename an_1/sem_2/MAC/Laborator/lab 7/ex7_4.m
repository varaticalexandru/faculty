clear
clc
close all

% Sistemul:
% x^2 + y^2 = 2
% x^2 - y^2 = 1

% Sistemul (f.canonica):
% x^2 + y^2 - 2 = 0
% x^2 - y^2 - 1 = 0

% rezolvarea pe cale simbolica
syms x y;

eq1 = x^2 + y^2 - 2;
eq2 = x^2 - y^2 - 1;

sol = solve(eq1,eq2, x,y)

%%

clear
clc
close all

% cerc de centru (0,0) si raza sqrt(2) 
theta=0:pi/60:2*pi; r=sqrt(2); 
x=r*cos(theta); y=r*sin(theta); 
plot(x,y,'r--') 
hold on 
% hiperbola echilatera de centru (0,0) si semiaxe 1 
% y^2=x^2-1 => x^2>=1, deci x<=-1 sau x>=1, 

% si y1=sqrt(x^2-1), y2=-sqrt(x^2-1)=-y1 
x1=-3:0.1:-1; y11=sqrt(x1.^2-1); y12=-y11; 
x2=sort(-x1); y21=sqrt(x2.^2-1); y22=-y21; 
plot(x1,y11,'b',x1,y12,'b',x2,y21,'b',x2,y22,'b') 
axis equal, grid, hold off 
[xcoord,ycoord]=ginput;
close all;

disp('Solutiile sistemului:')
for i = 1 : length(xcoord)
    sol = fsolve('f7_4',[xcoord(i),ycoord(i)])
end

