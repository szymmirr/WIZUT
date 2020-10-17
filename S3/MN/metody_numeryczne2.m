okno=figure
set(okno)
set(okno,'Name','MATLAB 2016')
set(okno,'NumberTitle','off')
kolor=get(okno,'Color')
set(okno,'Color',[0.34,0.32,0.78])
przycisk=uicontrol('Style','pushbutton','Position',[100,100,200,50],'String','OK','Callback','tekst2')
edycja=uicontrol('Style','edit','Position',[100,200,200,50])
