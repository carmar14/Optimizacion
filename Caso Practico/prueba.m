clear all
clc 
% PARAMETROS GENERALES
nn = 3; r=1; % nn: ORDEN DEL PROCESO; r: NUMERO DE SALIDAS
NN = 7; % ORDEN DEL VECTOR ESTIMADO DE PARAMETROS
% PARAMETROS DEL SISTEMA:
J = 0.01; % MOMENTO DE INERCIA DEL MOTOR (kgm2/s2)
Ke =0.01; Kt = 0.01; % CONSTANTE ELECTROMOTRIZ (Nm/A)
R = 12; % RESISTENCIA (Ohmios)
C = 0.5; % CONDENSADOR (uF)
L = 0.5; % INDUCTANCIA DE LA ARMADURA (H)
Kw = 1.8; % CONSTANTE TORSIONAL (Nm/rad)
% MODELO LINEAL DEL PROCESO EN TIEMPO CONTINUO
Ac = [-1/(R*C) -1/C 0;...
Kw/(L*Kw + Kt*Ke) 0 -Ke*Kw/(L*Kw + Kt*Ke);0 Kt/J 0];
Bc = [1/(R*C);0;0];
Cc = [0 0 1]; Dc = [0];
T = 0.05; % PERIODO DE MUESTREO
% MODELO LINEAL DISCRETO
[G,H,C,D]=c2dm(Ac,Bc,Cc,Dc,T,'zoh');
[num,den]=ss2tf(G,H,C,D);
a1 = den(2); a2 = den(3); a3=den(4);
b1 = num(2); b2 = num(3); b3=num(4);
% VERIFICANDO SI LA PLANTA TIENE ACCION INTEGRAL
% raices = eig(G); % NO TIENE POLOS z=0;

% ADICIONANDO ACCION INTEGRAL
G1 = [G zeros(3,1);-C*G 1];
H1 = [H;-C*H];
% CALCULO DE LA GANANCIA DEL CONTROLADOR
Q = [5 0 0 0;0 1 0 0;0 0 10 0;0 0 0 0.1];
R = [0.01];
% CONTROL OPTIMO DEL SISTEMA
% OBTENEMOS LA GANANCIA DEL CONTROLADOR APLICANDO dlqr
[KK,P]=dlqr(G1,H1,Q,R);
% SEPARAMOS LA ACCION INTEGRAL
K = [KK(1) KK(2) KK(3)];
KI = -KK(4);
% SIMULACION
N = 600; x=[0;0;0]; v=0; Y=0;
for k=1:N
r(k)=5*sign(sin(0.008*k)); Ref=r(k);
v = v + Ref - Y;
U = - K*x + KI*v;
% if(U > 24)
% U = 24;
% elseif(U < -24)
% U = -24;
% end
x = G*x + H*U;
Y = C(1,:)*x;
y(k) = Y; u(k) = U;
end
% GRAFICOS
t=linspace(0,N*T,N);
subplot(2,1,1)
plot(t,y(1:N),t,r(1:N)), grid
ylabel('Velocidad (rad/s)')
xlabel('Tiempo en segundos')
subplot(2,1,2)
plot(t,u(1:N)), grid
xlabel('Tiempo en segundos')
ylabel('Voltaje de control')