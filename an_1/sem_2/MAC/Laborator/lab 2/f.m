function y = f(x)

    for i = 1:length(x)
        if x(i)<0
            y(i) = sin(3*x(i))/(2*x(i));
        else
            y(i) = cos(3*x(i));
        end
    end
    
end