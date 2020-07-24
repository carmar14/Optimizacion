close all
global Kp Ki
FitnessFunction = @PIDmotorDC;
numberOfVariables=2;
A=[];
b=[];
Aeq=[];
beq=[];
lower=[0 0];
upper=[10 10];
opciones=optimoptions(@ga,'PopulationSize',25, 'popinitrange',[0 0;20 5],...
    'MaxGenerations',25,'PlotFcns',{@gaplotbestf,@gaplotbestindiv});
[x,fval] = ga(FitnessFunction,numberOfVariables,A,b,Aeq,beq,lower,upper,nolcon,opciones)

%Prueba del controlador final
Kp=x(1);Ki=x(2);
[t x y error esf]=sim('ModeloMotor');
figure
plot(t,y,t,esf)