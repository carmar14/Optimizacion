function ControlPIDmotor = PIDmotorDC(X)
%Se definen los genes del individuo como variables globales 
% para su uso en el diagrama de bloques
global Kp Ki
 %Se especifica el orden en el que se van a almacenar los genes en el
 %individuo
 Kp=X(1);
 Ki=X(2);
%Se simula el sistema en el diagrama de bloques
[t x y error esf]=sim('ModeloMotor');
%Se genera un arreglo vacio para almancenar los valores a evaluar
%en la función fitness
ErrorCuad=zeros(length(t),1);
EsfCuad=zeros(length(t),1);;
%error=zeros(length(t),1);
%Cálculo del error cuadrático
ErrorCuad=(error).^2; %salida vs entrada
EsfCuad=(esf).^2;
%Se genera la función fitness que determinará la aptitud de los individuos
w1=10;w2=1;
ControlPIDmotor=w1*mean(ErrorCuad)+w2*mean(EsfCuad);
% ControlPIDmotor=mean(ErrorCuad);
end