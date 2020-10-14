function M = kolos2(a)
M=eye(a)*2
j=a
for i=1:a
        M(i,j)=3;
        j=j-1;
    end
end
