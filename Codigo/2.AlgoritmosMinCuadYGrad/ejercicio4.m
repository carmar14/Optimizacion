close all
Rangox1=-10:0.1:10;
Rangox2=-4:0.1:4;
[X1,X2]=meshgrid(Rangox1,Rangox2);
Z=0.5*(X1.^2+10*X2.^2);
figure
surf(X1,X2,Z)
%%
close all
clear X1min
clear X2min
alpha = 0.01;
h=0.1;
X1min(1)=20*rand(1)-10;
X2min(1)=8*rand(1)-4;
for i=1:500
    DelX1=(0.5*(X1min(i)+h)^2+10*X2min(i)^2)-(0.5*(X1min(i))^2+10*X2min(i)^2);
    X1min(i+1)=X1min(i)+alpha*(-DelX1/h);
    DelX2=(0.5*(X1min(i))^2+10*(X2min(i)+h)^2)-(0.5*X1min(i)^2+10*X2min(i)^2);
    X2min(i+1)=X2min(i)+alpha*(-DelX2/h);
end
figure
contour(X1,X2,Z,50)
axis([-10 10 -4 4])
hold on
plot(X1min,X2min)
hold off