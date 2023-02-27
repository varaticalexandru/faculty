function vy = LagrangeInterp(x,y,vx)
    n = size(x, 2);
    L = ones(n,size(vx,2));
    if (size(x,2) ~= size(y,2))
        fprintf(1,'\nError!\nx and y must have the same number of elements\n');
        vy = NaN;
    else
        for i = 1 : n
            for j = 1 : n
                if (i ~= j)
                    L(i,:) = L(i,:) .* (vx-x(j))/(x(i)-x(j));
                end
            end
        end
        vy = 0;
        for i = 1 : n
            vy = vy + y(i)*L(i,:);
        end
end