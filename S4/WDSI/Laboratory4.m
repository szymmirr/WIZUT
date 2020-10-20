function Perceptron
clc
clear all
close all
I = 1000;
n = 2;
m = 100;
eta = 0.5;
ro = 0.28;
k = 0;
kmax = 2000;
hold on;
W = zeros (1,m+1);
for i=1:m
   W(i) = rand;
end

c = ones (m,3);
z=0;
for i=1:m
    c(i,2)=-1 + (1-(-1))*rand;
    c(i,3)=-1 + (1-(-1))*rand;
    plot(c(i,2), c(i,3), '.k');
end

X = ones (I,3);
X(:,2) = (2*pi).*rand(I,1);
X(:,3) = 2.*rand(I,1)-1;

Y = ones (I,1);
for i=1:I
   if abs(sin(X(i,2)))>abs(X(i,3))
      Y(i,1)=-1;
   end
   X(i,2) = X(i,2) / (2*pi)*2 - 1;
end

Z = ones(I,m);
for i=1:I
    for j=1:m
        Z(i,j+1)=exp(-((X(i,2)-c(j,2))^2+(X(i,3)-c(j,3))^2)/(2*ro^2));
    end
end

tic
while k < kmax
    j = 1;
    for i=1:length(Z)
        if W * Z(i,:)' > 0
            w = 1;
        else
            w = -1;
        end
        
        if Y(i,1) ~= w
            for b=1:(m+1)
                A(j,b) = Z(i,b);
            end
            A(j,b+1) = Y(i);
            j = j + 1;
        end
    end
    
    if j == 1
        break;
    end
    
    [wi,~] = size(A);
    r = randi(wi);
    Xk = A(r,1:end-1);
    W = W + eta*A(r,end)*Xk;
    
    k = k+1;
end
toc

[x,y] = meshgrid(-1:0.01:1);
for i=1:size(x,1)
    for j=1:size(y,1)
        for l=1:m
            t(l) = exp(-((x(i,j)-c(l,2))^2+(y(i,j)-c(l,3))^2)/(2*ro^2));
        end
        s = sum(W.*[1,t]);
        if s > 0
            w = 1;
        else
            w = -1;
        end
        z(i,j)=w;
    end
end

contour(-1:0.01:1,-1:0.01:1,z,'Color', 'c');



I = 1000;
n = 2;
m = 100;
eta = 0.5;
ro = 0.28;
k = 0;
kmax = 2000;
prog = 0;
czas = 0;
czas_rek = 0;
W_rek = 0;
prog_rek = 0;
klasyf_rek = 0;
hold on;
W = zeros (1,m+1);
for i=1:m
   W(i) = rand;
end

c = ones (m,3);
z=0;
for i=1:m
    c(i,2)=-1 + (1-(-1))*rand;
    c(i,3)=-1 + (1-(-1))*rand;
    plot(c(i,2), c(i,3), '.k');
end

X = ones (I,3);
X(:,2) = (2*pi).*rand(I,1);
X(:,3) = 2.*rand(I,1)-1;

Y = ones (I,2);
Y(:,2) = 0;
for i=1:I
   if abs(sin(X(i,2)))>abs(X(i,3))
      Y(i,1)=-1;
   end
   X(i,2) = X(i,2) / (2*pi)*2 - 1;
end

Z = ones(I,m);
for i=1:I
    for j=1:m
        Z(i,j+1)=exp(-((X(i,2)-c(j,2))^2+(X(i,3)-c(j,3))^2)/(2*ro^2));
    end
end

Z(:,end+1) = Y(:,1);
tic
while k < kmax
    i = randi(length(Z));
        if W * Z(i,1:end-1)' > prog
            w = 1;
        else
            w = -1;
        end
        
        if Y(i,1) ~= w
                Xk = Z(i,1:end-1);
                Z(i,end);
                W = W + eta*Z(i,end)*Xk;
                prog = prog - (eta*Z(i,end));
                Y(i,2) = 0;
        else
            Y(i,2) = Y(i,2)+1;
            if Y(i,2) > czas_rek
                czas_rek = Y(i,2);
                W_rek = W;
                prog_rek = prog;
            end
        end
    k = k+1;
end
toc

W = W_rek;
[x,y] = meshgrid(-1:0.01:1);
for i=1:size(x,1)
    for j=1:size(y,1)
        for l=1:m
            t(l) = exp(-((x(i,j)-c(l,2))^2+(y(i,j)-c(l,3))^2)/(2*ro^2));
        end
        s = sum(W.*[1,t]);
        if s > 0
            w = 1;
        else
            w = -1;
        end
        z(i,j)=w;
    end
end
contour(-1:0.01:1,-1:0.01:1,z,'Color', 'm');
hold on;




I = 1000;
n = 2;
m = 100;
eta = 0.5;
ro = 0.28;
k = 0;
kmax = 2000;
prog = 0;
czas = 0;
czas_rek = 0;
W_rek = 0;
prog_rek = 0;
klasyf_rek = 0;
hold on;
W = zeros (1,m+1);
for i=1:m
   W(i) = rand;
end

c = ones (m,3);
z=0;
for i=1:m
    c(i,2)=-1 + (1-(-1))*rand;
    c(i,3)=-1 + (1-(-1))*rand;
    plot(c(i,2), c(i,3), '.k');
end

X = ones (I,3);
X(:,2) = (2*pi).*rand(I,1);
X(:,3) = 2.*rand(I,1)-1;

Y = ones (I,2);
Y(:,2) = 0;
for i=1:I
   if abs(sin(X(i,2)))>abs(X(i,3))
      Y(i,1)=-1;
   end
   X(i,2) = X(i,2) / (2*pi)*2 - 1;
end

Z = ones(I,m);
for i=1:I
    for j=1:m
        Z(i,j+1)=exp(-((X(i,2)-c(j,2))^2+(X(i,3)-c(j,3))^2)/(2*ro^2));
    end
end

Z(:,end+1) = Y(:,1);
tic
while k < kmax
    i = randi(length(Z));
        if W * Z(i,1:end-1)' > prog
            w = 1;
        else
            w = -1;
        end
        
        if Y(i,1) ~= w
                Xk = Z(i,1:end-1);
                Z(i,end);
                W = W + eta*Z(i,end)*Xk;
                prog = prog - (eta*Z(i,end));
                Y(i,2) = 0;
        else
            Y(i,2) = Y(i,2)+1;
            klasyf = 0;
            
            if Y(i,2) > czas_rek
                for j=1:(length(Z))
                    if W * Z(j,1:end-1)' > prog
                        w = 1;
                    else
                        w = -1;
                    end

                    if Y(j,1) == w
                        klasyf = klasyf + 1;
                    end
                end
                if klasyf > klasyf_rek
                    czas_rek = Y(i,2);
                    W_rek = W;
                end
            end
        end
    k = k+1;
end
toc

W = W_rek;
[x,y] = meshgrid(-1:0.01:1);
for i=1:size(x,1)
    for j=1:size(y,1)
        for l=1:m
            t(l) = exp(-((x(i,j)-c(l,2))^2+(y(i,j)-c(l,3))^2)/(2*ro^2));
        end
        s = sum(W.*[1,t]);
        if s > 0
            w = 1;
        else
            w = -1;
        end
        z(i,j)=w;
    end
end
contour(-1:0.01:1,-1:0.01:1,z,'Color', 'r');

for i=1:length(X)
    if Y(i,1) == -1
        plot(X(i,2),X(i,3),'.b');
    else
        plot(X(i,2),X(i,3),'.g');
    end
end

end
