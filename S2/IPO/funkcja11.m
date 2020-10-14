function [x] = funkcja11()
    x=[0:0.01:5];
    y=sqrt((x.^2)+1)./(x+1);
plot(x,y)
grid on
end