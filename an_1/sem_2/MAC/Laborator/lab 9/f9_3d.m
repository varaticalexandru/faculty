function d = f9_3d(t,a)
    d = zeros(3,1);

    x = a(1);
    y = a(2);
    z = a(3);

    d(1) = y - 2.*z + sin(t) - 2.*x;
    d(2) = x + 2.*z - 2.*y;
    d(3) = 33.*x - 3.*y + 5.*z;
end