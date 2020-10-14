function [x] = funkcja14()
    x=[0:0.01:10];
    a=2;
    b=4;
hold on;
if x>b+a
   y=1;
   plot(x,y,'-r');
end
if b-a<=x<=b+a
    y=0.5.*(1+sin(pi*((x-b)./2*a)));
    plot(x,y);
end
if x<b-a
   y=0;
   plot(x,y);
end    
grid on
end