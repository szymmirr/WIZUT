clc
clear all
close all
sim ('satelita')
R = str2num( get_param ('satelita/Subsystem' , 'R'));
rs = str2num( get_param ('satelita/Subsystem' , 'rs'));
t=0.01;
for i=1:length(y)
   plot(0,0)
   daspect([1 1 1])
   axis([-10 10 -10 10])
   w=2*rs;
   h=2*rs;
   x1=x(i)-rs;
   y1=y(i)-rs;
   rectangle('Position',[x1,y1,w,h],'Curvature',[1 1])
   rectangle('Position',[-R,-R,2*R,2*R],'Curvature',[1 1])
   pause(t)
end