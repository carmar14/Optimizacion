clear
clc
close all
v = -5:0.01:5;	
[x y] = meshgrid(v);	
cond1 = double(4*x-5*y <=2);	
cond2 = double(2*x+4*y >=6);
cond3 = double(x-6*y<=-14);
cond1(cond1==0)=NaN;
cond2(cond2==0)=NaN;
cond3(cond3==0)=NaN;

cond = cond1.*cond2.*cond3;
surf(x,y,cond)
hold on
grid on
view(0,90)

% syms x y
x1=-1.25;
y1=2.125;
x2=4.3158;
y2=3.0526;

z1=8*x1-4*y1
z2=8*x2-4*y2
8*-1-4*4
8*-1-4*5
% [x1 y1]=solve(4*x-5*y-2,2*x+4*y-6);
% [x2 y2]=solve(4*x-5*y-2,x-6*y+14);
% [x3 y3]=solve(2*x+4*y-6,x-6*y+14);
% 
% x=double([x2 x3]);
% y=double([y2 y3]);
% 
% plot(x2,y2,'o','MarkerFaceColor',[1,0.3,1])
% plot(x3,y3,'o','MarkerFaceColor',[1,0.3,0.7])
% xlabel('x1')
% ylabel('x2')
% legend('Región factible','P1(4.3158,3.0526)','P2(-1.25,2.125)')


% z1= double(8*x1-4*y1)
% z2= double(8*x2-4*y2)
% z3=8*-5-4*5
% figure
% surf(x,y,cond1)
% grid on
% view(0,90)	
% 
% figure
% surf(x,y,cond2)
% grid on
% view(0,90)	
% 
% figure
% surf(x,y,cond3)
% grid on
% view(0,90)	