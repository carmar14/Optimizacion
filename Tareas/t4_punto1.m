clear 
close all
clc

fun=@(x) x(1)+abs(x(2))+x(3);
A=[1 1 0];
b=2;
Aeq=[2 0 1];
beq=0;
x0=[0 5 1]';
x = fmincon(fun,x0,A,b,Aeq,beq)

%lineal
fun=[1 1 1 1];
A=[1 1 -1 0;0 -1 0 0; 0 0 -1 0];
b=[2;0;0];
Aeq=[2 0 0 1];
beq=0;
x=linprog(fun,A,b,Aeq,beq)
