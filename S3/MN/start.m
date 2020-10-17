wynik=1
A = load('dane1.txt')
[w,k]=size(A)

B = A(:,end)
A (:,end)=[]
A(1,:)
A(:,1)
roz=w

wynik = Mirr_g(A,B)