clc
clear
A=[1 2;1 -2;2 2;1 0;0 1]
B=[8;2;10;0;0]
Z=[-1;-1;-1;1;1]
F=[3;2]

%w - ograniczenie
[w,k]=size(A)
l=1

for i=1:w-1
AT(1,:)=A(i,:)
BT(1,:)=B(i)
for j=i+1:w
AT(2,:)=A(j,:)
BT(2,:)=B(j)
R=AT^(-1)*BT
if(sum(isnan(R))==0)
if(sum(isinf(R))==0)
    T(:,l)=R
    l=l+1
end
end
end
end

f=0
for i=1:l-1
    f=0
    for j=1:w
        if Z(j)==-1
           if A(j,:)*T(:,i)<=B(j)
              f=f+1
           end
        end
        if Z(j)==1
            if A(j,:)*T(:,i)>=B(j)
              f=f+1
           end
        end
        if Z(j)==0
            if A(j,:)*T(:,i)==B(j)
              f=f+1
           end
        end
    end
    if f==w
        T2(:,l)=T(:,i)
        l=l+1
    end
end
x=min(T(1,:))-1:0.1:max(T(1,:)+1)
y=min(T(2,:))-1:0.1:max(T(2,:)+1)
hold on
for i=1:w
    if A(i,2)==0
        x=B(i)/A(i,1)
        plot(x,y)
    else
        x=min(T(1,:))-1:0.1:max(T(1,:)+1)
        y2=(B(i)-A(i,1)*x)/A(i,2)
        plot(x,y2)
    end
end
ch = convhull(T(:,1),T(1,:))
fill(T(k),T(k),'r')
