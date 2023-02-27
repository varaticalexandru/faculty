function f(r)
    if r<= 0
        r = 1;
    end
    
    radius = [r,0.5*r,2*r,0]
    cylinder(radius,100);
    grid;
    xlabel('x'); ylabel('y'); zlabel('z');
    colormap('default')
end