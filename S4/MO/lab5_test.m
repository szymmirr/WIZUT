clc;
close
clear all;

A = [2 1;3 3;2 0;1 0;0 1];
B = [10;24;8;0;0];
Z = [-1;-1;-1;1;1];
F = [300 200];
f = @(x,y) (300*x)+(200*y);
f2 = @(x,y) (-F(1)/F(2))*x+y*(F(1)/F(2));


[w,k] = size(A);

for i=1:w-1
    AT(1,:) = A(i,:);
    BT(1,:) = B(i,:);
    
    for j=i+1:w
        AT(2,:) = A(j,:);
        BT(2,:) = B(j,:);
        R(k,:) = AT\BT;
        k=k+1;
	end
end

[ww kk] = size(R);
for k=1:ww
    for l=1:kk
		if isnan(R(k,l)) || isinf(R(k,l))
			R(k,l) = 0;
        end
    end
end

limNum = 0;

for i=1:ww
    flag = 0;
    for j=1:w
   
        result = R(i,1)*A(j,1)+R(i,2)*A(j,2);

        if (Z(j,1) == -1)
            if result <= B(j);
				flag = flag + 1;    
            end
        end
        
        if (Z(j,1) == 1)
            if result >= B(j);
				flag = flag + 1;
            end
        end
        
        if (flag == w) 
            lims(limNum+1,:) = R(i,:);
            limNum = limNum + 1;
        end
    end
end

[tmp, index] = unique(lims,'rows','first');
multiples = setdiff(1:size(lims,1),index);
[hi, wi]  = size(multiples);
limNum = limNum - wi;
lims = unique(lims, 'rows');

[R1 R2] = size(lims);
k = convhull(lims(:, 1), lims(:, 2));
x = -1:0.01:10;

hold on

for i = 1:R1
    tab_lims(i) = f(lims(i,1),lims(i,2));
	
	X = [lims(k(i), 1), lims(k(i), 2)];
	if(i == R1)
		Y = [lims(k(1), 1), lims(k(1), 2)];
	else
		Y = [lims(k(i+1), 1), lims(k(i+1), 2)];
	end
	
	a = (Y(2) - X(2)) / (Y(1) - (X(1)));
	b = X(2) - a*X(1);
	f3 = @(x) a*x+b;
	
	if isnan(a) || isinf(a)
		plot(X(1), x);
	else
	    plot(x, f3(x));
	end
end

[maxVal,maxLoc] = max(tab_lims);
lims(maxLoc,:)
maxVal
lims
limNum

y = f2(x, lims(maxLoc, 2));

plot(lims(:,1),lims(:,2), '.');
fill ( lims(k,1),lims(k,2), 'r','facealpha', 1 ); 
plot(x, y, '--r')
hold off
