clc
close
clear
tic
[X,Y]=meshgrid([-10:0.5:10],[-10:0.5:10]);
Z=@(X,Y) X.^2+Y.^2;
subplot(2,1,1)
mesh(X,Y,Z(X,Y))
colormap(hot)
subplot(2,1,2)
contour(X,Y,Z(X,Y))
title('Metoda')
hold on
dx=[-8,-2,-2,0];
dy=[-5,-5,0,0];
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