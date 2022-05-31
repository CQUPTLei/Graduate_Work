close all
clear
clc

data=xlsread('light.xls');
data1=xlsread('light1.xls');

p1=plot(data(:,1),data(:,2));
hold on
grid on
p2=plot(data1(:,1),data1(:,2));

p1.LineWidth = 1.5;
p1.Color='#00CD00';
p1.LineStyle='--';

p2.LineWidth = 1.5;
p2.Color='#FF8C00';
p2.LineStyle='--';

xlabel('波长(nm)');
ylabel('吸光系数');
text(990,0.45,'HbO_2','FontWeight','bold')
text(990,0.35,'Hb','FontWeight','bold')

y1=0:0.1:1.2;
x1=ones(1,13)*660;
x2=ones(1,13)*880;
p3=plot(x1,y1);
p4=plot(x2,y1);

p3.LineWidth=1.5;
p3.Color='black';
p4.Color='black';
p4.LineWidth=1.5;
text(670,1.17,'红光','FontSize',12)
text(670,1.11,'660nm','FontSize',12)
text(890,1.17,'红外光','FontSize',12)
text(890,1.11,'880nm','FontSize',12)
