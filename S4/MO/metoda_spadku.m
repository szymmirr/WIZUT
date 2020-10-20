clc
close
clear
tic
[X,Y]=meshgrid([-5:0.1:5],[-5:0.1:5]);
Z=@(X,Y) X.^2+Y.^2;
%Z=@(X,Y) 100*(Y-X.^2).^2+(1-X).^2;
%Z=@(X,Y) -cos(X).*cos(Y).*exp(-((X-pi).^2+(Y-pi).^2))
subplot(2,1,1)
mesh(X,Y,Z(X,Y))
%colormap(hot)
subplot(2,1,2)
contour(X,Y,Z(X,Y))
title('Metoda spadku')
hold on
dx=[-8,-2,-2,0];
dy=[-5,-5,0,0];

x0=4;
y0=4;
krok=10;
dokl=0.1;

if(krok>dokl)
    
    dx(1)=x0;
    dy(1)=y0;

    %x(j+1)=x(j)+k;
    
    %x(j+2)=x(j+1)-2*k;
end


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