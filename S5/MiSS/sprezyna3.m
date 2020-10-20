clc
close all
clear all
sim('sprezyna')
m=10
l=3
t=0.1
sim ( 'sprezyna' ) % uruchom ien ie s ym ul a c j i modelu z a p i s a n e g o j a k o sprWahadlo
m = str2num( get_param ( 'sprezyna/Subsystem' , 'm' ) ) ; % p ob r an ie masy z modelu
l = str2num( get_param ( 'sprezyna/Subsystem' , 'l' ) ) ;
r=u(:,1)
%r1=u(2,:)
%u=u(3,:)
%u2=u(4,:)
fi=u(:,3)
l_max=l+max(r)
for i=1:length(fi)
    l1=(l+r(i));
    plot(-l1*sin(fi(i)), -l1*cos(fi(i)), 'b.','MarkerSize',20*m);
    axis([-1.1*l_max 1.1*l_max -1.1*l_max 1.1*l_max])
    line([0 -l1*sin(fi(i))],[0 -l1*cos(fi(i))],'Color','r','LineWidth',2);
    pause(t)
end
