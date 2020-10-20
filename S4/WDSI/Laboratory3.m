function Perceptron
clc
clear all
close all
I = 1000;
n = 2;
eta = 0.5;
W = zeros (1,n+1);
W(1) = rand;
W(2) = rand;
k = 0;
hold on

X = ones (I,3);
X(:,2) = rand(I,1);
X(1:I/2,3) = 0 + (0.4-0)*rand(I/2,1);
X(I/2:I,3) = 0.6 + (1-0.6)*rand(I/2+1,1);

Y = ones(I,1);
for i=1:I
    if X(i,3) > 0.6
        Y(i) = -1;
        plot(X(i,2), X(i,3), 'o','color',[0 0.6 0]);
    else
        plot(X(i,2),X(i,3),'ob');
    end
end

tic
while 1
    A = [];
    j = 1;
    for i=1:I
        if W * X(i,:)' > 0
            w = 1;
        else
            w = -1;
        end
        if Y(i) ~= w
            A(j,1) = X(i,1);
            A(j,2) = X(i,2);
            A(j,3) = X(i,3);
            A(j,4) = Y(i);
            j = j + 1;
        end
    end
    
    if j == 1
        break;
    end
    
    [wi,~] = size(A);
    r = randi(wi);
    Xk = [A(r,1), A(r,2), A(r,3)];
    W = W + eta*A(r,4)*Xk;
end
toc

x1 = 0 : 0.05 : 1;
x2 = -(W(1) + W(2) * x1) / W(3);
plot(x1,x2,'c');





I = 1000;
n = 2;
eta = 0.5;
W = zeros (1,n+1);
W(1) = rand;
W(2) = rand;
k = 0;
kmax = 2000;
prog = 0;
czas = 0;
czas_rek = 0;
W_rek = 0;
prog_rek = 0;
klasyf_rek = 0;
hold on

X = ones (I,3);
X(:,2) = rand(I,1);
X(1:I/2,3) = 0 + (0.4-0)*rand(I/2,1);
X(I/2:I,3) = 0.6 + (1-0.6)*rand(I/2+1,1);

Y = ones(I,2);
Y(:,2) = 0;

for i=1:I
    if X(i,3) > 0.6
        Y(i) = -1;
    end
end

X(:,end+1) = Y(:,1);
tic
while k < kmax
    i = randi(I);
        if W * X(i,1:end-1)' > prog
            w = 1;
        else
            w = -1;
        end
        
        if Y(i,1) ~= w
                Xk = X(i,1:end-1);
                X(i,end);
                W = W + eta*X(i,end)*Xk;
                prog = prog - (eta*X(i,end));
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
    
    [wi,~] = size(X);
    r = randi(wi);
    Xk = [X(r,1), X(r,2), X(r,3)];
    W = W + eta*X(r,4)*Xk;
end
toc

W = W_rek;

x1 = 0 : 0.05 : 1;
x2 = -(W(1)+0.3 + W(2) * x1) / W(3)+0.3;
plot(x1,x2,'m');





I = 1000;
n = 2;
eta = 0.5;
W = zeros (1,n+1);
W(1) = rand;
W(2) = rand;
k = 0;
kmax = 2000;
prog = 0;
czas = 0;
czas_rek = 0;
W_rek = 0;
prog_rek = 0;
klasyf_rek = 0;
hold on

X = ones (I,3);
X(:,2) = rand(I,1);
X(1:I/2,3) = 0 + (0.4-0)*rand(I/2,1);
X(I/2:I,3) = 0.6 + (1-0.6)*rand(I/2+1,1);

Y = ones(I,2);
Y(:,2) = 0;

for i=1:I
    if X(i,3) > 0.6
        Y(i) = -1;
    end
end

X(:,end+1) = Y(:,1);
tic
while k < kmax
    i = randi(length(X));
        if W * X(i,1:end-1)' > prog
            w = 1;
        else
            w = -1;
        end
        
        if Y(i,1) ~= w
                Xk = X(i,1:end-1);
                X(i,end);
                W = W + eta*X(i,end)*Xk;
                prog = prog - (eta*X(i,end));
                Y(i,2) = 0;
        else
            Y(i,2) = Y(i,2)+1;
            klasyf = 0;
            
            if Y(i,2) > czas_rek
                for j=1:(length(X))
                    if W * X(j,1:end-1)' > prog
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
    
    [wi,~] = size(X);
    r = randi(wi);
    Xk = [X(r,1), X(r,2), X(r,3)];
    W = W + eta*X(r,4)*Xk;
end
toc

W = W_rek;

x1 = 0 : 0.05 : 1;
x2 = -(W(1)+0.3 + W(2) * x1) / W(3)+0.3;
plot(x1,x2,'r');

end
