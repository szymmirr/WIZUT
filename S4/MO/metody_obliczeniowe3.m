clc
close
clear
tic
figure(2)
[X,Y]=meshgrid([-20:0.1:20],[-20:0.1:20]);
%Z=@(X,Y) X.^2+Y.^2;
%Z=@(X,Y) 100*(Y-X.^2).^2+(1-X).^2;
Z=@(X,Y) -cos(X).*cos(Y).*exp(-((X-pi).^2+(Y-pi).^2))
subplot(2,1,1)
mesh(X,Y,Z(X,Y))
%colormap(hot)
subplot(2,1,2)
contour(X,Y,Z(X,Y))
hold on

x0=3.5;
y0=3.5;
lambda=0.9;
dokl=0.0001;

dfx=@(x,y)((Z(x+0.001,y)-Z(x-0.001,y))/(2*0.001));
dfy=@(x,y)((Z(x,y+0.001)-Z(x,y-0.001))/(2*0.001));

gradient = [dfx(x0,y0);dfy(x0,y0)];

dx(1)=x0;
dy(1)=y0;
i=3;
p=[dx(1);dy(1)];
alfa=lambda/norm(gradient);
while norm(gradient)>0.1
    p=p-alfa*gradient;
    gradient = [dfx(p(1),p(2));dfy(p(1),p(2))];
    dx(i)=p(1)
    dy(i)=p(2);
    i=i+1;
    if (dx(i-1)==dx(i-3))
       alfa=alfa-0.01;
    end
    if (i==50000)
        break
    end
end

i-3
dx(i-1)
dx(i-2)
dy(i-1)
dy(i-2)

plot(dx(1),dy(1),'rp')
text(dx(1),dy(1),'START')
plot(dx(2:end-1),dy(2:end-1),'g.')
plot(dx(end),dy(end),'rp')
text(dx(end),dy(end),'STOP')
for i=1:length(dx)-1
    line([dx(i),dx(i+1)],[dy(i),dy(i+1)])
end
toc
%wspolrzedne punktu minimum
%wartosc funkcji w punkcie minimum
%liczba iteracji
%czas
%http://geatbx.com/docu/fcnindex-01.html#TopOfPage
