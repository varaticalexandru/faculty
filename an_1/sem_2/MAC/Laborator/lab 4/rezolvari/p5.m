syms alfa beta gama
A=[alfa -beta 1;-gama 1 beta;1 gama -alfa];
B=[gama;alfa;beta];
det(A) %se observã cã det(A)!=0
disp('Sitem compatibil determinat')
sol=simplify(inv(A)*B)
sol=A\B

% punctul b
clear, clc
syms a b c p q
A=[a -b 0; -b b -c; 0 c a]; B=[p; -2*q; p+q];
d=factor(det(A))
disp(blanks(1)')
disp('Caz I. a~=0 si a*b+c^2~=b^2 => sistem compatibil determinat')
sol=simplify(inv(A)*B); x=sol(1), y=sol(2), z=sol(3)
pause, disp(blanks(1)')
disp('Caz II. a==0')
A1=subs(A,a,0)
% -b*y=p, c*y=p+q => b*c*y=-c*p=b*(p+q)
disp('Caz. II.1. b*(p+q)+c*p~=0 => sistem incompatibil')
pause, disp(blanks(1)')
disp('Caz. II.2. b*(p+q)+c*p==0')
pause, disp(blanks(1)')
disp('Caz. II.2.1.1. b=0, c=0, p=0, q=0 => sistem compatibil nedeterminat')
disp('solutia: x,y,z reali oarecare')
pause, disp(blanks(1)')
disp('Caz. II.2.1.2. (b=0 si c=0) si (p~=0 sau q~=0) => sistem incompatibil')
pause, disp(blanks(1)')
disp('Caz II.2.2. b=0 si c~=0')
disp('Caz II.2.2.1. p~=0 => sistem incompatibil')
pause
disp('Caz II.2.2.2. p==0 => sistem compatibil nedeterminat')
disp('solutia: x real oarecare, y=q/c, z=2*q/c')
pause, disp(blanks(1)')
disp('Caz II.2.3. b~=0')
A2=A1(1:2,1:2), detA2=det(A2)
disp('det(A2)~=0 => rangA==2')
disp('sistem compatibil nedeterminat')
syms z; B2=B(1:2)-z*A1(1:2,3);
sol2=A2\B2; x=sol2(1), y=sol2(2), disp('z real oarecare')
pause, disp(blanks(1)')
disp('Caz III. a~=0 si a*b+c^2-b^2==0')
A3=A([1 3],[1 3]), detA3=det(A3)
disp('det(A3)~=0 => rangA==2')
pause, disp(blanks(1)')
disp('Caz III.1. b*p+c*(p+q)~=2*a*q => rang[A B]==3')
disp('=> sistem incompatibil')
pause, disp(blanks(1)')
disp('Caz III.2. b*p+c*(p+q)==2*a*q => rang[A B]==2')
disp('sistem compatibil nedeterminat')
syms y; B3=B([1 3])-y*A([1 3],2);
sol3=A3\B3; x=sol3(1), disp('y real oarecare'), z=sol3(2)

