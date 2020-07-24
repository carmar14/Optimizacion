close all
N = 2;

[x1,x2] = meshgrid( -4:0.05:4, -4:0.05:4);

f = 10*N + (x1.^2 - 10*cos(2*pi*x1))+(x2.^2 - 10*cos(2*pi*x2));
f2 = 10*N + (x1^2 - 10*cos(2*pi*x1))+(x2^2 - 10*cos(2*pi*x2));
surf(x1,x2,f)
figure
surf(x1,x2,f2)

%%
close all
lim = 15;
[x,y] = meshgrid( -lim:0.5:lim, -lim:0.5:lim);

f = 0.5+ ((sin(sqrt(x.^2+y.^2)).^2)-0.5)./(1+(0.1*(x.^2+y.^2)));

surf(x,y,f)