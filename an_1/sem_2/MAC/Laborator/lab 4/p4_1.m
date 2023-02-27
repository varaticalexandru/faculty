clear
clc
close all

A = [4 3 -1; -1 1 1; 1 0 3];
b = [2; 0; -1];

[sol x] = sys(A,b)