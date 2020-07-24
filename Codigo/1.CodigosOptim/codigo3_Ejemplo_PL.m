close all
F=[1 1];
A=[-5/3 -1; -3/5 -1];
B=[-5;-3];
Aeq=[];
Beq=[];
Lb=[0 0];
Ub=[5 5];
[X,Feval]=linprog(F,A,B,Aeq,Beq,Lb,Ub)

