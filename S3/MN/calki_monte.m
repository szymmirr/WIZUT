f=inline('sin(x)+1')
xp=-pi
xk=pi
n=10000
x=(xk-xp)*rand(1,n)+xp
srednia=sum(f(x))/n
r=srednia*(xk-xp)

z=quad(f,xp,xk)
