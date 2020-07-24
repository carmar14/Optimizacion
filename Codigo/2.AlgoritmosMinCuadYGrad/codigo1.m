%%
close all
x=0:0.2:5;
N=length(x);
y=(0.5*x.^2+3)+0.05+randn(1,N);
figure
plot(x,y,'ob');
%%
Phi=[[x.^2]' ones(N,1)];
Y=y';
theta=Phi\Y;            %\ division izquierda, 
Yest=theta(1)*x.^2+theta(2);
figure
plot(x,Yest,'or'); hold on
plot(x,y,'ob'); hold on
