function g = f7_9(v)
    x = v(1);
    y = v(2);
    z = v(3);

    g = x/(x.^2+y.^2+z.^2+1);
end