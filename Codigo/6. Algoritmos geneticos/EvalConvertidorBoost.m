function Fitness=EvalConvertidorBoost(X)
%Se definen los genes del individuo como variables globales
%para su uso en el diagrama de bloques
global Entrada Salida EntradaEst SalidaEst
global w0est w1est best
%Se especifica el orden en el que se van a almacenar los genes en el
%individuo
w0est=X(1);
w1est=X(2);
best=X(3);
%Se simula el sistema en el diagrama de bloques
[t x]=sim('convertidorBoost_2017a');
%Se genera un arreglo vacio para almacenar los valores a evaluar
%en la función fitness
restas=zeros(length(Salida),1);
%Se realiza elemente a elemento el error cuadratico medio
%y se almacenan en los vectores vacios
restas=(Salida-SalidaEst).^2; %salida vs entrada
%Se genera la función fitness que determinará la aptotud de los individuos
Fitness=mean(restas);
end