clear
clc
close all

r = 6371;
[x,y,z] = sphere(360/15);
z = z * r;

surf(x,y,z);
grid


