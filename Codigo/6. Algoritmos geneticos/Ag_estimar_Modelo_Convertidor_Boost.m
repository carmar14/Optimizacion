global Entrada Salida EntradaEst SalidaEst
global w0est w1est best

opciones=optimoptions(@ga,'popinitrange',[0 0 0;5e3 5e3 1e3], ...
    'CrossoverFraction',0.8,'CrossoverFcn',{@crossoverheuristic},'PopulationSize',20, ...
    'PlotFcns',{@gaplotbestf,@gaplotbestindiv});
A=[];
b=[];
Aeq=[];
beq=[];
lower=[0 0 0];
upper=[5e3 5e3 1e3];
nolcon=[];
[Xfin fitnessfin] = ga(@EvalConvertidorBoost,3,A,b,Aeq,beq,lower,upper,nolcon,opciones)

w0est=Xfin(1)
w1est=Xfin(2)
best=Xfin(3)
[t x]=sim('convertidorBoost_2017a');
figure();
plot(Tiempo,Salida,Tiempo,SalidaEst);
