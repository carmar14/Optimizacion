clear 
close all
clc
syms x y l1 u1 u2 s1 s2
L=x^2+y^2+l1*(x+y-5)+u1*(-x*y+4+s1^2)+u2*((x-4)^2+(y-2)^2-1+s2^2)
f=gradient(L) %[fx fy fl1 fu1 fu2 fs1 fs2]
sol=solve(2*x+l1-u1*y+2*u2*(x-4),2*y+l1-u1*x+2*u2*(y-2),x+y-5,-x*y+4+s1^2,(x-4)^2+(y-2)^2-1+s2^2,2*u1*s1,2*u2*s2)
H=hessian(L,[x y l1 u1 u2 s1 s2]);
Ha=[H(1:2,1:2) zeros(2,2);zeros(2,4)]+[zeros(2,4); zeros(2,2) H(end-1:end,end-1:end)];

%Puntos estacionarios
P1=[4,1,-10,-2,0,0,0];
P2=[4,1,-8,0,-3,0,0];
P3=[3,2,-4,0,1,-sqrt(2),0];
P4=[3,2,-4,0,1,sqrt(2),0];
%Evaluacion de los puntos en la Hessiana Orlada
H1=double(subs(Ha,[x y l1 u1 u2 s1 s2],P1));
H2=double(subs(Ha,[x y l1 u1 u2 s1 s2],P2));
H3=double(subs(Ha,[x y l1 u1 u2 s1 s2],P3));
H4=double(subs(Ha,[x y l1 u1 u2 s1 s2],P4));

%Definiendo matriz siguiendo el criterio de los autovalores
e1=eig(H1);
e2=eig(H2);
e3=eig(H3);
e4=eig(H4);

%ejemplo Hessiana Orlada
% L=x^2+12*x*y+2*y^2+l1*(4*x^2+y^2-25);
% H=hessian(L,[x y l1])