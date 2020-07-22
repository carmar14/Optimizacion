clear
clc
close all

%Datos experimentales punto a)
s=[5 19.5 44]'; %Distancia medida en metros
t=[1 2 3]';     %Tiempo en segundos
%Se arma el sistema
Y=s;
phi=t.^2/2;
tetha=phi\Y; %Calculo del parametro g en m/s^2
g=tetha;
%Comprobando modelo
se=g*t.^2/2;

plot(t,s,'or')
hold on
plot(t,se)
legend('Datos experimentales','Modelo')
xlabel('Tiempo (s)');
ylabel('Distancia(m)');
grid on
title('Punto 5 a')

%Datos experimentales punto b)
s=[5 19.5 44 78.5]'; %Distancia medida en metros
t=[1 2 3 4]';     %Tiempo en segundos
%Se arma el sistema
Y=s;
phi=t.^2/2;
tetha=phi\Y; %Calculo del parametro g en m/s^2
g=tetha;
%Comprobando modelo
se=g*t.^2/2;

figure
plot(t,s,'or')
hold on
plot(t,se)
legend('Datos experimentales','Modelo')
xlabel('Tiempo (s)');
ylabel('Distancia(m)');
grid on
title('Punto 5 b')
