function [f] = funkcja7(n)
f1=1;
f2=1;
if n==1
    f=1;
end
if n==2
   f=1;
end
for i=3:n
    f=f1+f2;
    f1=f2;
    f2=f;
end
end