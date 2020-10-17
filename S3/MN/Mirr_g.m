function [wynik] = Mirr_g(A,B)
[w,k]=size(A)
for i=1:w
    B(i)=B(i)./A(i,i)
    A(i,:)=A(i,:)./A(i,i)
    for j=i+1:w
        B(j)=B(j)-B(i)*A(j,i)
        A(j,:)=A(j,:)-A(i,:)*A(j,i)
    end
end
wynik=1
wynik(end)=B(end)
for i=w-1:-1:1
    wynik(i)=B(i)-A(i,i+1)*B(i-1)-A()*B(i-2)
end
A
B
