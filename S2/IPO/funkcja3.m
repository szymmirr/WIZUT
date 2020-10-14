function [w] = funkcja3(a,b)
if a~=b
    w=1+((a+b)/(a-b))^2;
else
    w=1+((a+b)/(a*b));
end
end