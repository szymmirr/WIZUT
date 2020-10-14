function x = sabplot()
    x=[-6:0.01:6];
    y=x./((x.^2)-4);
    subplot(2,4,3)
plot(x,y,'r')
grid on
end