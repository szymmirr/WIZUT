function N = pierwszycztery(M)
%N = mod(M,2) * 1 + ~mod(M,2) * 2
Mnieparz = (M==mod(M,2)) * 0

nieparz1=unique(Mnieparz)
if(nieparz1(1)==0)
    min=nieparz1(2)
end
if(nieparz1(1)~=0)
    min=nieparz1(1)
end
maks=nieparz1(end)
%nie dziala