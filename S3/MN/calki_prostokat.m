f=inline('sin(x)+1')
xp=-pi
xk=pi
x=[xp:0.01:xk]
y=sin(x)+1
s=0
n=10
dx=(xk-xp)./n
plot(x,y)
for i=1:n
    s=s+f(xp+(i*dx))
    x0=xp+(i*dx)
    y0=f(xp+(i*dx))
    i=i+1
    line([x0,x0+dx,x0+dx,x0,x0],[0,0,y0,y0,0])
end
s=s*dx
s
z=quad(f,xp,xk)


    
        