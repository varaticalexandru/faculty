function dy = f9_4(x,y)
    dy = zeros(2,1);
    
    dy(1) = y(2);
    dy(2) = 2*y(2) - 3*x.^2.*y(1);
end