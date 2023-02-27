function y = f2_5(x)
    if ~imag(x)
        y = 1/(1+exp(-3*x));
    else
        y = 'x trebuie sa fie nr. reale sau vector de nr. reale';
    end
end