function f3_2(f,a,b)
    if a>b
        disp('Domeniul vid (a<b)!')
        return
    end

    n = 100;        % nr. de puncte pt. interval  - 1
    pas = (b-a)/n;  % pas de reprezentare 

    if a==b x=a;
    else x = a:pas:b;
    end

    if a<=0 | min(feval(f,x))<=0
        disp(['Cel putin unul din graficele in coordonate ' ...
            'semilogaritmice nu poate fi reprezentat !'])
        return
    end

    % coord. semilog. pe axa x
    subplot(2,1,1);
    semilogx(x,feval(f,x))
    hold on
    xlabel('x')
    ylabel('y')
    title('logx')
    hold off

    % coord. semilog. pe axa y
    subplot(2,1,2);
    semilogy(x, feval(f,x))
    hold on
    xlabel('x')
    ylabel('y')
    title('logy')
    hold off

end