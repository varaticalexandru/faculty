function dy = f9_3b(t,y)
    dy = zeros(2,1);

    dy(1) = y(2);
    dy(2) = y(2) + 2.*y(1).*sin(t);
end