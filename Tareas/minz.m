function minz(x0,y0,N)
clc
close all
% clear

xk=x0;%-2.2;
yk=y0;%1.2;
e=1e-4;
%N=100; %Numero de pasos
alp=1;
f=zeros(1,2);
f(1)=fx(xk,yk);
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
for k=1:N
    %Calcular gradiente
    [px py]=gradf(xk,yk);
    ngrad=sqrt(px^2+py^2);
    if ngrad<=e
        g2=plot3(xk1(1:end-1),yk1(1:end-1),zk(1:end-1),'b','LineWidth',2);
        break
        
    else
       %Direccion de descenso
       dxk=-px;
       dyk=-py;
       for t=1:N+1
           %Calculo de aplha
           alpn=(0.5)^(t-1)*alp;
           f(2)=fx(xk+alpn*dxk,yk+alpn*dyk);
           if f(2)<(f(1)+alpn*(px*dxk+py*dyk)*10^-4)
                alp=alpn;
                break
           end
       end
       %Actualización
       xk1(k+1)=xk+alp*dxk;
       yk1(k+1)=yk+alp*dyk;
       zk(k+1)=fx(xk1(k+1),yk1(k+1));
       xk=xk1(k+1);
       yk=yk1(k+1);
       
       plot3(xk1(1:end-1),yk1(1:end-1),zk(1:end-1),'*k','LineWidth',2)
       pause(0.2)     
    end
    
end


%Resultado
if k==N ngrad>e
    display("No se encontró el mínimo, por favor seleccione otro punto inicial")
else
    g3=plot3(xk1(end),yk1(end),zk(end),'or','LineWidth',2);
    legend([g1 g2 g3],'z=x\ite^{-x^{2}-y^{2}}','Trayectoria desde (x0,y0) hasta el mínimo','Ubicación del mínimo')
    display("El minimo se encuentra en el punto:")
    punto=[xk1(end) yk1(end)]
    display("y su valor es:")
    z=zk(end)
    display("este valor se encontro en la iteración número: ")
    k
end