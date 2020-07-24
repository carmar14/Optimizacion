close all
Rangox1=-10:0.1:10;
Rangox2=-4:0.1:4;
[X1,X2]=meshgrid(Rangox1,Rangox2);
Z=100*(X1 - X2.^2).^2 + (1 - X2).^2;
figure
surf(X1,X2,Z)

%%  Solución sin Restricción 1
options = optimoptions(@fminunc,'Algorithm','quasi-newton');
x0=[4,4];  %starting guess
[x,fval,exitflag,output]=fminunc(@rosenbrock,x0,options)

% %%  Solución sin Restricción 2, hay que especificar el gradiente objetivo
% options = optimoptions(@fminunc,'Algorithm','trust-region');
% x0=[4,4];  %starting guess
% [x,fval,exitflag,output]=fminunc(@rosenbrock,x0,options)

%% Solución con Restricciones

A=[1 1];
B=[2];
Aeq=[];
Beq=[];
Lb=[-2,-1];
Ub=[2,3];
x0=[1/4,1/4];
fun=@rosenbrock;
nonlcon=@Ros_Restriccion;
[x,fval,exitflag,output]=fmincon(fun,x0,A,B,Aeq,Beq,Lb,Ub,nonlcon)

