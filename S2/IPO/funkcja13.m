function [x] = funkcja13()
    x=[0:0.01:10];
hold on;
for k=1:5
    y=k*sin(pi*x);
    plot(x,y);
end
grid on
end