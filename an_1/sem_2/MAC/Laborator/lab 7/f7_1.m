function g = f7_1(v)
    x = v(1); y = v(2); z = v(3);

    g(1) = x*y + z  + 3;
    g(2) = x/z - y + 2;
    g(3) = y*z + x - 6;
end