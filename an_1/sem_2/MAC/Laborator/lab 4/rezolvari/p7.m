clear; clc;
linii=500; coloane=700;
A=rand(500,700); x=rand(700,1);b=A*x;
if rank(A)==rank([A b]) && rank(A)~=coloane
disp('Sistemul compatibil nedeterminat')
tic;
y1=pinv(A)*b;
timp=toc
tic;
y2=A\b;
timp=toc
er1=norm(A*y1-b)
er2=norm(A*y2-b)
er1/er2
end
