function [a,b,x,y]=regrMatriz(a,b,x,y)
bt=transpose(b);
abt=Aumentada(a,bt);
disp(abt);
c=rref(abt);
disp('Coeficientes')
disp(c);
j=size(c,2);
i=size(c,1);
cb=c(:,j);
ct=transpose(cb);
ctt=fliplr(ct);
display(ctt);
x2=linspace(-2,(max(x)+2));
vy=polyval(ctt,x2);
plot(x,y,'r*',x2,vy,'g');

