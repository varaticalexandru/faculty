function pp = ProdPartial(v)
    i = 1;
    pp = 1;

    while i<=length(v) && v(i)>0
        pp = pp*v(i);
        i = i+1;
    end
end