x=[-1:0.01:1]
y=1./((25*(x.^2))+1)
xw=linspace(-1,1,10)
yw=1./((25*(xw.^2))+1)
yi=interp1(xw,yw,x,'spline')
yi2=interp1(xw,yw,x,'v5cubic')
plot(x,y)
hold on
plot(xw,yw,'r*')
plot(x,yi,'g')
plot(x,yi2,'y')