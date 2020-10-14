function N = pierwszyczteryv2(M)
unik=unique(M)
j=1
for i=1:size(unik)
    if(mod(unik(i),2)~=0)
        nieparz(j)=unik(i)
        j=j+1
    end
end
if(nieparz(1)==0)
    min=nieparz(2)
end
if(nieparz(1)~=0)
    min=nieparz(1)
end
maks=nieparz(end)
