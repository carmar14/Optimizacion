clear
close all
clc
ci=20;
[t,u]=ode45(@f,[0 10],ci);
plot(t,u)