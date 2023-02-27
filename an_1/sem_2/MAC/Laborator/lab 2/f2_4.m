function [in, rang] = f2_4(A)
    rag=[];in=[];

    [r c] = size(A)
    if r ~= c
        disp('Matricea nu este patratica!')
        return
    end
    
    rang = rank(A)
    if ~det(A)
        disp("Matricea este singulara, nu este inversabila")
        in = [];
        return
    else
        disp("Matricea este nesingulara, este inversabila")
        in = inv(A)
    end

end