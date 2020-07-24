close all
x=0:0.2:5;
N=length(x);
y=(0.2*x.^3+0.5*x.^2+3)+randn(1,N);
figure
plot(x,y,'-b');
%%
Phi=[[x.^3]' [x.^2]' ones(N,1)];
Y=y';
theta=Phi\Y;            %\ division izquierda, 
Yest=theta(1)*x.^3+theta(2)*x.^2+theta(3);
figure
plot(x,Yest,'-r'); hold on
plot(x,y,'-b'); hold on
