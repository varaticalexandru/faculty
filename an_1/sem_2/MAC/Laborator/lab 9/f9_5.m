function dy = f9_5(x,y)
    dy = zeros(2,1);

    dy(1) = y(1) + y(2);
    dy(2) = x - y(1);
end