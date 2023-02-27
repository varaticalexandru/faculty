function hexagon(p)
    color = ["red", "blue", "black"];
    x = [2 2 0; 2 0 0; 0 -2 0; -2 -2 0; -2 0 0; 0 2 0];
    y = [-1 1 0; 1 2 0; 2 1 0; 1 -1 0; -1 -2 0; -2 -1 0];
    r = mod(p, 3);

    for i = 1:6
        fill(x(i, :), y(i, :), color(r+1));
        hold on
        r = r - 1;
        if r == -1
            r = mod(p, 3);
        end
    end

end