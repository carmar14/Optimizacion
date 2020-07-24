close all
close all
Rangox1=-1:0.01:1;
Rangox2=-1:0.01:1;
[X1,X2]=meshgrid(Rangox1,Rangox2);
Z=10-exp(-(X1.^2+3*X2.^2));
figure
surf(X1,X2,Z)
%%
close all
clear X1min
clear X2min
alpha = 0.15;
X1min(1)=1;
X2min(1)=1;
for i=1:1000
    X1min(i+1)=X1min(i)+alpha*(-X1min(i));
    X2min(i+1)=X2min(i)+alpha*(-10*X2min(i));
end
figure
contour(X1,X2,Z,50)
axis([-1 1 -1 1])
hold on
plot(X1min,X2min)
hold off