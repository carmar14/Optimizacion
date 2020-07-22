function minz2(x0,y0,N)
%Funcion que encuentra el minimo de f(x,y)=z=x*exp^(-x^2-y^2)
%x0 valor inicial de la componente x
%y0 valor inicial de la componente y
%N numero de iteraciones
clc
close all
%Condiciones iniciales
xk=x0;
yk=y0;
e=1e-5;%tolerancia
%%Vectores que guardarán la información del punto (x,y) asi como 
% la imagen z en cada iteración
xk1(1)=xk;
yk1(1)=yk;
zk(1)=fx(xk1(1),yk1(1));
%Grafica de la superficie
x=-2:0.1:2;
y=x;
[X Y]=meshgrid(x,y);
Z = X.*exp(-X.^2-Y.^2);
tamano=get(0,'ScreenSize');
figure('position',[tamano(1) tamano(2) tamano(3) tamano(4)]);
g1=surf(X,Y,Z,'FaceAlpha',0.3);
hold on
grid on
title('z=x\ite^{-x^{2}-y^{2}}')
syms a
%Algoritmo de máximo descenso
for k=1:N
    %Calcular gradiente del punto (x,y)
    [px py]=gradf(xk,yk);
    %Calcular norma del gradiente en el punto (x,y)
    ngrad=sqrt(px^2+py^2);
    %Confirmación de criterio de parada por tolerancia
    if ngrad<=e
        %Grafica la unión de los puntos encontrados (trayectoria que siguio
        %el algoritmo desde el punto inicial (x0,y0,z0) hasta el mínimo
        g2=plot3(xk1(1:end),yk1(1:end),zk(1:end),'b','LineWidth',2);
        break
    else
       %Direccion de descenso
       dxk=-px;
       dyk=-py;
       
       %Calculo de aplha
       h=fx(xk+a*dxk,yk+a*dyk)-fx(xk,yk);% h(alpha)
       dh=diff(h); %primera derivada de h(alpha)
       d2h=diff(dh); %Segunda derivada de h(alpha)
       alp=double(solve(dh==0,a)); %Solución de la primera derivada de h(alpha)=0
       %Verificando si el  alpha encontrado es un mínimo, usuando la
       %segunda derivada
       if double(subs(d2h,a,alp(1,1)))>0
           alpm=alp(1,1);
       elseif double(subs(d2h,a,alp(2,1)))>0
           alpm=alp(2,1); 
       end
       %Actualización para el paso siguiente
       xk1(k+1)=xk+alpm*dxk;
       yk1(k+1)=yk+alpm*dyk;
       zk(k+1)=fx(xk1(k+1),yk1(k+1));
       xk=xk1(k+1);
       yk=yk1(k+1);
       %Grafica del punto (x,y,z) encontrado en cada iteración
       plot3(xk1(1:end-1),yk1(1:end-1),zk(1:end-1),'*k','LineWidth',2)
       pause(0.2)     
    end
    
end


%Resultado
if k==N && ngrad>e
    display("No se encontró el mínimo, por favor seleccione otro punto inicial")
else
    %Grafica el mínimo encontrado
    g3=plot3(xk1(end),yk1(end),zk(end),'or','LineWidth',2);
    legend([g1 g2 g3],'z=x\ite^{-x^{2}-y^{2}}','Trayectoria desde (x0,y0) hasta el mínimo','Ubicación del mínimo')
    display("El minimo se encuentra en el punto:")
    punto=[xk1(end) yk1(end)]
    display("y su valor es:")
    z=zk(end)
    display("Este valor se encontró en la iteración número: ")
    k
end