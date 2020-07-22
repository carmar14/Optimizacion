clear
clc
close all
% Parametos
load('modelo.mat');
%Matrices A,B,Q
Ts=0.01;
A=modelo3var.A;
B=modelo3var.B;
C=modelo3var.C;
D=modelo3var.D;
sis=ss(A,B,C,D);
step(sis)
% C=[0 0 1];
% sis=ss(A,B,C,D);
% hold
% step(sis)
tf=0.5;
% State equations
syms x1(t) x2(t) x3(t) p1(t) p2(t) p3(t) u H f;
Dx1 = diff(x1,t)== A(1,1)*x1+A(1,2)*x2+A(1,3)*x3+B(1,1)*u;
cx1=  x1(0)==0;
Dx2 = diff(x2,t)== A(2,1)*x1+A(2,2)*x2+A(2,3)*x3+B(2,1)*u;
cx2=  x2(0)==0;
Dx3 = diff(x3,t)== A(3,1)*x1+A(3,2)*x2+A(3,3)*x3+B(3,1)*u;
cx3=  x3(tf)==2;
% Cost function inside the integral

f = 0.5*u^2;
% Hamiltonian

H = f + p1*Dx1 + p2*Dx2 + p3*Dx3;
% Costate equations
Dp1 = diff(p1,t)== -(A(1,1)*p1+A(2,1)*p2+A(3,1)*p3);
cp1=  p1(tf)==0;
Dp2 = diff(p2,t)== -(A(1,2)*p1+A(2,2)*p2+A(3,2)*p3);
cp2=  p2(tf)==0;
Dp3 = diff(p3,t)== -(A(1,3)*p1+A(2,3)*p2+A(3,3)*p3);
cp3=  p3(tf)==0;
% solve for control u
sol_u=-(p1*B(1,1)+p2*B(2,1)+p3*B(3,1));
% du = diff(H,u)==0;
% sol_u = solve(du, u);
% Substitute u to state equations
Dx1 = subs(Dx1, u, sol_u);
Dx2 = subs(Dx2, u, sol_u);
Dx3 = subs(Dx3, u, sol_u);
% [x_1, x_2, x_3, p_1, p_2, p_3] 
solu= dsolve([Dx1;Dx2;Dx3;Dp1;Dp2;Dp3],[cx1;cx2;cx3;cp1;cp2;cp3]);
% convert symbolic objects to strings for using 'dsolve'
% syms x1(t) x2(t) x3(t) p1(t) p2(t) p3(t)
% eq1 = strcat('Dx1=',char(Dx1));
% x1i= x1(0)==0;
% x1f=x1(tf)==u;
% eq2 = strcat('Dx2=',char(Dx2));
% x2i= x2(0)==0;
% eq3 = strcat('Dx3=',char(Dx3));
% x3i= x3(0)==0;
% eq4 = strcat('Dp1=',char(Dp1));
% p1f= p1(tf)==0;
% eq5 = strcat('Dp2=',char(Dp2));
% p2f= p2(tf)==0;
% eq6 = strcat('Dp3=',char(Dp3));
% p3f= p3(tf)==0;
% sol_h = dsolve(eq1,eq2,eq3,eq4,eq5,eq6);
% % sol_h = dsolve(Dx1,Dx2,Dx3,Dp1,Dp2,Dp3);
% %% use boundary conditions to determine the coefficients
% %    case a: (a) x1(0)=x2(0)=0; x1(2) = 5; x2(2) = 2;
% % conA1 = 'x1(0) = 0';
% % conA2 = 'x2(0) = 0';
% % conA3 = 'x1(2) = 5';
% % conA4 = 'x2(2) = 2';
% sol_a = dsolve(eq1,eq2,eq3,eq4,conA1,conA2,conA3,conA4);
