function [m] = funkcja8(n)
m=zeros(n);
m(1,1)=1;
for i=2:n
    m(i,i)=1;
    m(i,i-1)=1;
end
end