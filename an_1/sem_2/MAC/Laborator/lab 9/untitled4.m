clear
clc
close all

sol = fminbnd('exp(-0.4*x)*cos(8*x)', 0, 1)

