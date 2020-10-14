function M = dwadziesiec(n,a,b)
M = zeros(2*n);
for i = 1:n
    M(i:2*n-i+1,i) = ones(2*(n-i+1),1)*a;
    M(i:2*n-i+1,2*n-i+1) = ones(2*(n-i+1),1)*b;
end