close all
rx1=0:0.05:5;
rx2 = rx1;
[x1,x2] = meshgrid( rx1, rx2);

f = x1+x2;
surf(x1,x2,f)
view(35,35)

%%
[F,C]=size(x1);
for i=1:F
    for j=1:C
        if ((x2(i,j)+(5/3)*x1(i,j)-5)>=0)&&((x2(i,j)+(3/5)*x1(i,j)-3)>=0)
            x3(i,j)=x1(i,j)+x2(i,j);
        else
            x3(i,j)=0;
        end
    end
end
figure
surf(x1,x2,x3)
view(35,35)

%%
figure
contour(x1,x2,x3,50)
axis([0 5 0 5])
hold on
fplot('-(5/3)*x+5',[0 5],'r')
fplot('-(3/5)*x+3',[0 5],'r')