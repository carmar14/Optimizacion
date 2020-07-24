close all
% Una compañia fabrica y venden dos modelos de lampara
% L1 y L2. Para su fabricación se necesita un trabajo manual de 20 minutos 
% para el modelo L1 y de 30 minutos para el L2; y un trabajo de maquina para 
% L1 de 20 minutos y 10 minutos para L2. Se dispone para el trabajo manual de
% 100 horas al mes y para la maquina 80 horas al mes. Sabiendo que el 
% beneficio por unidad es de 15 y 10 euros para L1 y L2, respectivamente,
% planificar la producción para obtener el maximo beneficio

%Max{f(x1,x2)=15x1+10x2}
%    f(x1,x2)=-15x1-10x2
% (1/3)*x1+(1/2)*x2 menorQ 100
% (1/3)*x1+(1/6)*x2 menorQ 80

F=[-15 -10];
A=[1/3 1/2; 1/3 1/6];
B=[100;80];
Aeq=[];
Beq=[];
Lb=[0 0];
Ub=[1000 1000];
[X,Feval]=linprog(F,A,B,Aeq,Beq,Lb,Ub)

%%
% En una granja de pollos se da una dieta, para engordar, con una
% composición minima de 15 unidades de una sustancia A y otras 15 de
% una sustancia B. En el mercado solo se encuentra dos clases de 
% compuestos: el tipo X con una composición de una unidad de A y 5 de B,
% y el otro tipo, Y, con una composición de cinco unidades de A y una de
% B. El precio del tipo X es de 10 euros y del tipo Y es de 30 euros. 
% Que cantidades se han de comprar de cada tipo para cubrir las necesidades
% con un coste minimo?

%Min{f(x1,x2)=10x1+30x2}
%  x1=A+5B
%  x2=5A+B
%  A = x1-5B
%  B = x2-5A
%  A = (x1/24)+(5x2/24)
%  B = (5x1/24)-(x2/24)
% A mayorQ 15
% B mayorQ 15
% (x1/24)+(5x2/24) menor 15
% (5x1/24)-(x2/24) menor 15

F=[10 30];
A=[-1/24 -5/24; -5/24 1/24];
% A=[1 5; 5 1];
B=[-15;-15];
Aeq=[];
Beq=[];
Lb=[0 0];
Ub=[1000 1000];
[X,Feval]=linprog(F,A,B,Aeq,Beq,Lb,Ub)

%%

