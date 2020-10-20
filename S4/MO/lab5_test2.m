clc;
clear all;

A = [2 1;3 3;2 0;1 0;0 1]
B = [10;24;8;0;0]
Z = [-1;-1;-1;1;1]
k=1;
f = @(x,y,z) (100*x)+(120*y);

%_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
[w,k] = size(A);

for i=1:w-1
    
    AT(1,:) = A(i,:)
    BT(1,:) = B(i,:)
    
    for j=i+1:w
        
        AT(2,:) = A(j,:)
        BT(2,:) = B(j,:)
        R(k,:) = AT\BT;
        k=k+1;
      
end
end

[ww kk] = size(R);
for k=1:ww
    for l=1:kk
        if R(k,l) == Inf || R(k,l) == (-Inf)
           R(k,l) = 0;
        end
    end
end

licznik = 1;
for i=1:ww
    flag = 0;
    for j=1:w
   
        result = R(i,1)*A(j,1)+R(i,2)*A(j,2);
        %Mniejsze
        if (Z(j,1) == -1)
            if result <= B(j);
            flag = flag + 1;    
            end
        end
        
        %Wiêksze
        if (Z(j,1) == 1)
            if result >= B(j);
            flag = flag + 1;
            end
        end
        
        %Równe
        if (Z(j,1) == 0)
            if result == B(j);
            flag = flag + 1;
            end
        end
        
        if (flag == w) 
            WYNIK(licznik,:) = R(i,:);
            licznik = licznik + 1;
        end
    end
end

[R1 R2] = size(WYNIK);
tab_wynik = zeros(R1,1);

for i = 1:R1
    tab_wynik(i,1) = f(WYNIK(i,1),WYNIK(i,2));
end

[mw,mp] = max(tab_wynik);

wartoscMax = mw
wspolrzedne = WYNIK(mp,:)
