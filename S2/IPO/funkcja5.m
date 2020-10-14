function [m] = funkcja5(n)
m=zeros(n);
for i=1:n
    m(i,i)=i;
end
end