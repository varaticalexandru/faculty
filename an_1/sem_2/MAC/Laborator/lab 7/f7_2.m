function g = f7_2(v)
    a = v(1);
    b = v(2);
    c = v(3);
    d = v(4);

    g(1) = a - 2*b + c;
    g(2) = b - 2*c + d;
    g(3) = (a-2)*(c-7) - (b-6)^2;
    g(4) = (b-6)*(d-8) - (c-7)^2;
end