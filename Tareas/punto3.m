clear
close all
clc
[x y]=meshgrid(-3:0.1:3,-3:0.1:3);
p=[-5 0 5];

% z=zeros(1,length(x));

for i=1:length(p)
    z=x.^4-2*p(i)*x.^2-y.^2+3; 
    figure
    surf(x,y,z)
    
end
% legend('p<0','p=0','p>0')
