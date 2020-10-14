function [x] = funkcja12()
    x=[0:0.01:2*pi];
    y=((cos(x).^2)+1)./((x.^2+1)).^2;
plot(x,y)
grid on
end