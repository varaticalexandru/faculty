% a11*x + a12*y + a13*z = b1
% a21*x + a22*y + a23*z = b2
% a31*x + a32*y + a33*z = b3

% matricea sistemului
% A = [
%       a11 a12 a13;
%       a21 a22 a23;
%       a31 a32 a33;
% ];

% matricea termenilor liberi
% b = [
%       b1 b2 b3;
% ];

% matricea extinsa
% [A b]

function [sol x] = p_6(A, b)

[l c] = size(A);
if (l ~= length(b)) 
    sol = 'Matrice de dimensiuni incorecte';
    return
end

if rank(A) == rank([A b])
    sol = 'Sistem compatibil';
    if rank(A) == c              % inv(A) * b daca A -> matrice patratica, det(A) ~= 0
        sol = [sol ' determinat'];
        x = pinv(A) * b; % metoda pseudo-inversei
        % x = A \ b;       % impartirea la stanga

    else
        sol = [sol ' nedeterminat']
        x = pinv(A) * b; % metoda pseudo-inversei
        % x = A \ b;       % impartirea la stanga
    end
else
    sol = 'Sistem incompatibil';
    x = [];
end

end



