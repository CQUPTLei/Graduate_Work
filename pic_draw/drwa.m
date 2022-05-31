%第四章，标定
close all
clear
clc

data = xlsread('data.xls');
x=data(:,1);
y=data(:,2);

plot(x,y,'*');
grid on
hold on
% legend('苹果','小米','三星','华为','Imagine Marketing','其他');

[a,r]=polyfit(x,y,1)  %拟合系数

y1=polyval(a,x);

R2 = norm(y1 -mean(y))^2/norm(y - mean(y))^2

plot(x,y1,'r-')
text(0.62,97.5,'y = -32.626*R + 116.964','Color','red','FontSize',12)
text(0.645,97,'R^2 = 0.923','Color','blue','FontSize',10)
xlabel('本设备测得的R值');
ylabel('可孚血氧仪测得的血氧饱和度(%)');
