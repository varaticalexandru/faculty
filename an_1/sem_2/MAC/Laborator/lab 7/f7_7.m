function g = f7_7(v)
    x = v(1);
    y = v(2);
    z = v(3);

    g = (x*y*z) / ((x-y)^2 + (y-z)^2 + 1);
end