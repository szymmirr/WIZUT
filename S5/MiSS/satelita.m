clc
clear all
close all
sim ('satelita')
R = str2num( get_param ('satelita/Subsystem' , 'R'));
rs = str2num( get_param ('satelita/Subsystem' , 'rs'));
t=0.01;
for i=0:length(y)
   plot(0,0)
   daspect([1 1 1])
   axis([-10 10 -10 10])
   rectangle('Position',[x1,y1,w,h])
   rectangle(['Curvature',[1 1])
   pause(t)
end