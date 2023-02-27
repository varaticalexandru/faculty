function y=f(x)
x_n=[];x_p=[];
if(imag(x)~=0)
    y='Valorile lui x nu sunt real';
    return
end
x_n=x(x<0); x_p=x(x>=0);
y=[sin(3*x_n)./(2*x_n) cos(3*x_p)];
