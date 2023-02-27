clc
clear

% A = [
%     -6 8 -1;
%     2 -3 0;
% ]
% 
% 
% b = [
%      -5;
%      7;
% ]
% 
% [sol, x] = p_6(A, b);
% 
% disp('x = ')
% disp(x(1))
% 
% disp('y = ')
% disp(x(2))
% 
% disp('z = ')
% disp(x(3))

% A = [
%     4 3 -1;
%     -1 1 1;
%      1 0 3;
%      4 4 3
% ];
% 
% b = [
%     2;
%     0;
%     -1;
%     1
% ];
% 
% A = [
%     -6 -8 1;
%     2 -3 0
% ];
% 
% b = [
%     -5;
%     7
% ];

% rank(A)
% -6 + 8x = -5 + z
% 2x - 3y = 7

syms z            % variabila simbolica z 
A = [
    -6 8;
     2 -3;
];

b = [
    -5 + z;
    7;
];

x = pinv(A) * b;
disp('x = ');
disp(x(1));
disp('y = ');
disp(x(2));



% syms x            % variabila simbolica x
% A = [
%     8 -1;
%     -3 0;
% ];
% 
% b = [
%     -5 + 6*x;
%     7 - 2*x;
% ];
% 
% x = pinv(A) * b;
% disp('y = ');
% disp(x(1));
% disp('z = ');
% disp(x(2));

% A = [
%      3 0 0; 
%      2 3 0; 
%      3 1 4;
% ];
% 
% B = [
%      1 7 2; 
%      7 3 1; 
%      2 1 0;
% ];
% 
% inv(A * B)
% inv(B) * inv(A)

