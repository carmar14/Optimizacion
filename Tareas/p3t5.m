
clear
close all
clc

%%Constantes
c1=6;
c2=-3;
t=0:0.1:1;

x1=t.^3*(c1+1)/2-t.^2*c2/4;
x2=t.^2*(c1+1)/4-t*c2/2;

u=-(c2-t*(c1+1))/2;

plot(t,x1,'b',t,x2,'r',t,u,'k')
hold on
plot(t(end),1,'bo')
plot(t(end),1,'bo')
plot(t(end),1,'bo')
legend('x1(t)','x2(t)','u(t)')
grid on
xlabel('Tiempo(s)')
title('Evolución de los estados y Control Optimo')