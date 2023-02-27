clc
clear

x = -0.5:0.1:0.5;
plot(x, (x-1).^4-tan(x), x, zeros(size(x)))

x = fzero('ectrans2', [-0.5, 0.5])