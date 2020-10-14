function N = trzecidwa(M)
N=M
for i=1:numel(N)
    if(N(i)==round(N(i)))
        N(i)=1;
    end
    if(N(i)~=round(N(i)))
        N(i)=-1;
    end
end