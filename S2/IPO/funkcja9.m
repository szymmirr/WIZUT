function [m] = funkcja9(n,a,b)
m=zeros(2*n);
for i=1:2*n
    m(i,i)=a;
end
for j=2*n:1
    for k=1:2*n
        m(k,j)=b;
    end
end
end