function M = drugitrzy(n,a,b)
M=eye(2*n)*a
j=2*n
for i=1:2*n
        M(i,j)=b;
        j=j-1;
    end
end
