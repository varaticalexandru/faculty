function [sol X] = sys(A,b)
    [r c] = size(A);
    X = [];

    if rank(A) == rank([A b])
        % compatibil
        sol = 'Sistem compatibil ';
        if (rank(A) == c)
            % determinat
            sol = [sol, 'determinat'];
            X = pinv(A) * b;
        else
            % nedeterminat
            sol = [sol, 'nedeterminat'];
            X = [pinv(A)*b, A\b];
        end
    else
        % imcompatibil
        sol = 'Sistem incompatibil';
    end
end