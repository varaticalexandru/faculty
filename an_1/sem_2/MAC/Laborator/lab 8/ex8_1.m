clear
clc
close all


% ex8_1

%{
  sa se det. val. de aproximare ale f. in punctele:
  0.7, 1.3, 1.7, 2.5, 2.9
  folosind :
  a) interpolare liniara
  b) interpolare liniara cu pol. Hermite cubic pe portiuni
%}  

x = [0 1.2 1.6 2 2.7 3];
y = [-2.5 0 2 1.7 -4 1];
vx = [0.7 1.3 1.7 2.5 2.9];
vy_linear = [];
vy_cubic = [];

%%
% a) interpolare liniara
disp('Valorile de aproximare a lui f prin interpolare liniara:')
vy_linear = interp1(x,y,vx,"linear")

%%
% b) interpolare liniara cu pol. Hermite cubic pe portiuni
disp('Valorile de aproximare a lui f prin interpolare Hermite cubica:')
vy_cubic = interp1(x,y,vx,"pchip")
% vy_cubic = interp1(x,y,vx,"cubic")

%%
plot(x,y,'b');
hold on
grid
plot(vx,vy_linear,'rd-');
plot(vx,vy_cubic,'kx-');
legend('puncte','interpolare liniara','interpolare Hermite')
hold off


