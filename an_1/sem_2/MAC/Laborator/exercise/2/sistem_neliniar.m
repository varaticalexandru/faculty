function sys = sistem_neliniar(v)
    x = v(1);
    y = v(2);
    z = v(3);

    sys(1) = (y + z)/x - 2.3;
    sys(2) = x + y - z - 27.5;
    sys(3) = (x-y)^2 + 2*z - 80;
end