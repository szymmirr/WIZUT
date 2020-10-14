function x = drugijeden(x,y,z)
vx = -pi:0.2:pi;
vy = -pi:0.2:pi;
[x,y] = meshgrid(vx, vy);
z = cos(x.*x + y.*y)./(x.*x + y.*y + 1);
mesh(x,y,z);
