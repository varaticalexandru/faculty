clear
clc
close all

x0 = 1;
y0 = 0;
z0 = -1;

% vectorul valorilor de aproximare initiala a solutiei
v0 = [x0; y0; z0];

% rezolvarea sistemului
% x,y,z
sol = fsolve('f7_1',v0);