xg=[0,1,3,4,5]
yg=[0,1,2,1,0]
xgi=xg(1):0.01:xg(end)
ygi=interp1(xg,yg,xgi,'cubic')
plot(xgi,ygi)
hold on

xd=[0,1,3,4,5]
yd=[0,-0.7,-1,-0.7,0]
xdi=xg(1):0.01:xd(end)
ydi=interp1(xd,yd,xdi,'cubic')
plot(xdi,ydi)
hold on