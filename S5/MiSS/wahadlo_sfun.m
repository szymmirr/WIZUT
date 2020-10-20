function [sys,x0,str,ts] = wahadlo_sfun(t, x, u, flag, l, m, fi0)
    switch flag,
    case 0
    [sys,x0,str,ts] = mdlInitializeSizes(l, m, fi0, 0); % Initialization
    case 2,
    sys = mdlUpdate(t,x,u,l);
    case { 1 ,3, 4, 9 }
    sys = []; % Unused flags
    otherwise
    error(['Unhandled flag = ',num2str(flag)]); % Error handling
    end
end
%==============================================================
function [sys,x0,str,ts] = mdlInitializeSizes(l,m,fi0,to)
    % Call function simsizes to create the sizes structure.
    sizes = simsizes;
    % Load the sizes structure with the initialization information.
    sizes.NumContStates= 0;
    sizes.NumDiscStates= 0;
    sizes.NumOutputs= 0;
    sizes.NumInputs= 1;
    sizes.DirFeedthrough=1;
    sizes.NumSampleTimes=1;
    % Load the sys vector with the sizes information.
    sys = simsizes(sizes);
    x0 = []; % No continuous states
    str = []; % No state ordering
    ts = [to 0]; % Inherited sample time
    Inicjalizacja(l,m,fi0);
end
%==============================================================
function sys = mdlUpdate(t,x,u,l)
    fig = get_param(gcbh,'UserData');
    if ishandle(fig),
        ud = get(fig,'UserData');
        % Aktualizacja rysunku
        set(ud.s,'XData',-l*sin(u),'YData', -l*cos(u)) ;
        set(ud.p,'XData',[0 -l*sin(u)],'YData',[0 -l*cos(u)]) ;
        drawnow
        pause(0.01)
    end;
    sys = [];
end
%==============================================================
function Inicjalizacja(l,m,fi0)
    close all
    FigureName = 'Wizualizacja wahadla';
    Fig = figure('Name', FigureName);
    % Pierwsze rysowanie wahad³a
    hold on
    p = line([0 -l*sin(fi0)],[0 -l*cos(fi0)],'Color','r','LineWidth',2);
    s = plot(-l*sin(fi0), -l*cos(fi0), 'b.','MarkerSize',5*m);
    hold off
    % Ustawienia osi
    axis([-1.1*l 1.1*l -1.1*l 1.1*l])
    set(gca,'DataAspectRatio',[1 1 1])
    set(gca,'XTick',[-l 0 l],'YTick',[-l 0 l])
    % Zapamiêtanie uchwytów na wykresy
    FigUD.p = p;
    FigUD.s = s;
    set(Fig,'UserData',FigUD);
    set_param(gcbh,'UserData',Fig);
end
