clear
clc
close all

% se se determine
% pornind de la valorile (1 2 3 4), cvadruplul
% (a,b,c,d) care satisface simultan conditiile

% a,b,c,d - progresie aritmetice
% a-2,b-6,c-7,d-8 - progresie geometrica

% precizie: 10^(-30)


% Sistemul: 
% a + c = 2b
% b + d = 2c
% (a-2)*(c-7) = (b-6)^2
% (b-6)*(d-8) = (c-7)^2

% Sistemul (forma canonica):
% a - 2b + c = 0
% b - 2c + d = 0
% (a-2)*(c-7) - (b-6)^2 = 0
% (b-6)*(d-8) - (c-7)^2 = 0

options = optimset('TolX', 10^(-30), 'TolFun', 10^(-30));

a0 = 1;
b0 = 2;
c0 = 3;
d0 = 4;

v0 = [a0; b0; c0; d0];

[sol gval] = fsolve('f7_2', v0, options)


