function h = ellipse(xc,yc,a,b)
    hold on

    t = 0 : pi/100 : 2*pi;
    x = xc + a*cos(t);
    y = yc + b*sin(t);

    h = plot(x,y);

    hold off
end