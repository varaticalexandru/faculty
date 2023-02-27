function g = f7_4(v)
    x = v(1);
    y = v(2);

    g = [x.^2+y.^2-2; x.^2-y.^2-1];
end