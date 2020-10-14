function [x] = funkcja10()
    x=[-6:0.01:6];
    y=x./((x.^2)-4);
plot(x,y,'r')
grid on
end