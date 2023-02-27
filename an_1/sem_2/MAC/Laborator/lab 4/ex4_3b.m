clear
clc
close all

A = [3 -1 1 -2; -4 4 2 1];
b = [6 0]';
X = [];

[sol X] = sys(A,b)

