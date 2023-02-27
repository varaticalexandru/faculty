function dy = sistem_derivate(x,y)
    % dy = zeros(2,1);

    dy(1) = 2.*y(1) + x + x.^2 + 2;
end