clear
close all
clc
ci=[1;2]; %Condiciones iniciales [u(0); v(0)]
[t,dx]=ode45(@sed,[0 100],ci); %Aplicaci�n del m�todo n�merico 
plot(t,dx)
grid on
legend('u(t)','v(t)')
xlabel('tiempo(s)')