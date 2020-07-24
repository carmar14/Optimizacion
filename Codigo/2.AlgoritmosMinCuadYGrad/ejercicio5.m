close all
R=2;
L=0.01;
t=0:0.005/50:0.05;
N=length(t);
Imed=(1/R)-((1/R).*exp((-R/L).*t)+0.01*randn(1,N));
figure
plot(t,Imed,'ob')
%%
close all
fun = @(x)(1/x(1))-((1/x(1)).*exp((-x(1)/x(2)).*t))-Imed;

Ib=[0,0];
ub=[5,0.1];
x0=[3,0.05];
options = optimoptions(@lsqnonlin,'Display','iter');
x=lsqnonlin(fun,x0,Ib,ub,options);
figure
plot(t,Imed,'ob',t,fun(x)+Imed,'or')