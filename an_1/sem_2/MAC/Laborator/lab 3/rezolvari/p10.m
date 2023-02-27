clear;clc;close all
R=6371;
[x y z]=sphere(360/15);
surf(x,y,z*R)