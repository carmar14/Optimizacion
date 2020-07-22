clear
close all
clc
syms y(t) x(t)
eqn = diff(y,t) == -1-y;
cond = y(1) == 0;
eqn1 = diff(x,t) == -1-y;
cond1= x(0) == 0.5*exp(2)-1;
[x y]=dsolve([ eqn1; eqn],[cond1;cond]);

[V,D] = eig([1 -1; -3 -1]);
[V,D] = eig([3/2 1/2; 3/2 -3/2]);

syms y(t) x(t)
eqn = diff(y,t) == (-3*y+3*x)/2;
cond = y(5) == 0;
eqn1 = diff(x,t) == (3*x+y)/2;
cond1= x(1) == 2;
[x y]=dsolve([ eqn1; eqn],[cond1;cond]);
%U optimo
% pretty(x)
% pretty(y)

simplify(x)
simplify(y)
%lambda2
syms x(t) t
eqn = diff(x,t) == 1;
cond = x(1) == 0;
[x]=dsolve(eqn,cond);
%x2
syms x(t) t
eqn = diff(x,t) == -(t-1)/2;
cond = x(0) == 0;
[x]=dsolve(eqn,cond);

%x1
syms x(t) t
eqn = diff(x,t) == -t*(t-2)/4;
cond = x(0) == 0;
cond1=x(1)==1;
[x]=dsolve(eqn);


%%%%%Punto 5%%%%%%%%%%%%%%%
t=0:0.1:1;
c1=-7;
c2=-6;
c6=0;
u=3-3*t;
x1=(c1+1)*t.^3/12-c2*t.^2/4+c6; 
x2=t.^2*(c1+1)/4-t*c2/2;
figure
plot(t,u,t,x1,t,x2)
legend('Control u(t)','x1(t)','x2(t)')
