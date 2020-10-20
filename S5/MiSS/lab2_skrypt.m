clc
close all
clear all
sim('lab_2_3')
m=10
l=3
t=0.1
for i=1:length(fi)
    plot(-l*sin(fi(i)), -l*cos(fi(i)), 'b.','MarkerSize',5*m);
    axis([-1.1*l 1.1*l -1.1*l 1.1*l])
    line([0 -l*sin(fi(i))],[0 -l*cos(fi(i))],'Color','r','LineWidth',2);
    pause(t)
end