function h = circle(xc,yc,r)
    hold on
    t = 0 : pi/100 : 2*pi;

    x = r * cos(t) + xc;
    y = r * sin(t) + yc;
    
    h = plot(x,y);
    
    hold off
end