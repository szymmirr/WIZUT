clear all
clc
x=1:0.01:2
y=x.^3-x-1
plot(x,y)
grid on
hold on
f=@(x) x.^3-x-1
x0=1
while abs(f(x0))>0.00001
x0=x0-((x0.^3-x0-1)/(3*x0.^2-1))
end
