function [m] = funkcja6(n)
m=zeros(n);
for i=1:n
    for j=1:n
        m(i,j)=5^(i*j);
    end
end
end