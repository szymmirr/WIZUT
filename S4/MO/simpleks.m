clc
clear
A=[2 1 1 0 0;3 3 0 1 0;2 0 0 0 1]
B=[10;24;8]
F=[300,200]
[w,k]=size(A)
cj=[F,zeros(1,w)]
AB=[B,A]
wb=w:1:k
cb=[cj(wb(1));cj(wb(2));cj(wb(3))]
wwf=cb'*AB(:,1)
for i=2:k+1
    ww(i-1)=cb'*AB(:,i)-cj(i-1)
end

while 1
    [wart,kk]=min(ww)
    if wart>=0
        disp ('Koniec')
        wwf
        break
    end
    for i=1:w
    if AB(i,kk+1)>0
        tmp(i)=AB(i,1)./AB(i,kk+1)
    else
        tmp(i)=Inf
    end
    end

    [wart1,wk]=min(tmp)
    ER=AB(wk,kk+1)

    AB(wk,:)=AB(wk,:)/ER
    for i=1:w
        if i~=wk
            AB(i,:)=AB(i,:)-AB(wk,:)*AB(i,kk+1)
        end
    end

    wb(wk)=kk
    cb=[cj(wb(1));cj(wb(2));cj(wb(3))]
    wwf=cb'*AB(:,1)
    for i=2:k+1
        ww(i-1)=cb'*AB(:,i)-cj(i-1)
    end
end
