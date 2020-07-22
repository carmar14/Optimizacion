clear
clc
close all
%Codigo prueba máximo descenso
%min (x1-2)^4+(x1-2x2)^2
% x1=-20:0.2:20;
% x2=x1';
syms x1 x2 alpha
fx=(x1-2).^4+(x1-2*x2).^2;

%Etapa 0: seleccionar condicion inicial x(0)  ? R^(n ),k=0
pasos=10;
x10=0.00;
x20=3.00;
e=1e-5;
x1k1=zeros(1,pasos);
x2k1=x1k1;
x1k1(1)=x10;
x2k1(1)=x20;
gradf=gradient(fx);
gradfp=zeros(2,pasos);
d=gradfp;
%k=0;
for k=1:pasos
%Etapa 1: Calcular ?f(x(k))
%[px py]=gradient(f);
%gradf=[4(x1-2)^3+2(x1-2x2)
%       -4(x1-2x2)]

gradfp(:,k)=double(subs(gradf,[x1 x2],[x1k1(k) x2k1(k)]));
normg(k)=norm(gradfp(:,k));
% normg(k)
% k
%Calcular ||?f(x(k))|| en k=0;
% f(k)=(x1k1(k)-2)^4+(x1k1(k)-2*x2k1(k))^2;
% px1g(k)=4*(x1k1(k)-2)^3+2*(x1k1(k)-2*x2k1(k));
% px2g(k)=-4*(x1k1(k)-2*x2k1(k));
% normg(k)=sqrt(px1g(k)^2+px2g(k)^2);
% normg=

if normg(k)<=e
    break
else
    %Etapa 2: 
    %Calcular dirección de máximo descenso d(k)=-?f(x(k))
    %     dx1(k)=-px1g(k);
    %     dx2(k)=-px2g(k);
    d(:,k)=-gradfp(:,k);
    h(k)=(x1k1(k)+alpha*d(1,k)-2)^4+(x1k1(k)+alpha*d(1,k)-2*(x2k1(k)+alpha*d(2,k)))^2;
    %     %Calcular alpha(k)
    dh(k)=diff(h(k));
    alp=vpa(solve(dh(k)));
    %h=(x1(k)+alpha*dx1(k)-2).^4+(x1(k)+alpha*dx1(k)-2*x2).^2;
    %Calcular paso siguiente:  x(k+1)=x(k)+?(k)*d(k)
    alph(:,k)=real(double(alp));
    x1k1(k+1)=x1k1(k)+alph(1,1)*d(1,k);
    x2k1(k+1)=x2k1(k)+alph(1,1)*d(2,k);
    
end
end