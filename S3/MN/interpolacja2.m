%5.30, -1stC
clear
x=[5,6,8,11]
y=[-2,3,7,10]
plot(x,y,'r*')
hold
n=length(x)
for i=1:n
    for j=1:n
        v(i,j)=x(i).^(j-1);
    end
end
v
y=y'
v1=inv(v)
a=v1*y
w=0
xx=5:0.01:11
w=w+a(1)
for i=2:n
    w=w+(a(i).*xx.^(i-1))
end
plot(xx,w)
