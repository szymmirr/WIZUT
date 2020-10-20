newImg = imread('litery_1.png');
grayImage= rgb2gray(newImg);
roberts = edge(grayImage,'roberts');
H = fspecial('laplacian');
laplace = imfilter(newImg,H);
prewitt = edge(grayImage,'prewitt');
size(grayImage)
sobel = edge(grayImage,'sobel',0.1);

imageIn = double(grayImage);
[N M L] = size(imageIn);
g = double( (1/15)*[5 5 5;-3 0 -3; -3 -3 -3] );
kirschImage = zeros(N,M,8);
for j = 1:3
    theta = (j-1)*45;
    gDirection = imrotate(g,theta,'crop');
    kirschImage(:,:,j) = conv2(imageIn,gDirection,'same');
end
imageOut = zeros(N,M);
for n = 1:N
    for m = 1:M
        imageOut(n,m) = max(kirschImage(n,m,:));
    end
end
kirsch = imageOut;

subplot(2,3,1);
imshow(grayImage);
xlabel({['Obraz']})
 
subplot(2,3,2);
imshow(roberts);
xlabel({['Roberts']})

subplot(2,3,3);
imshow(laplace);
xlabel({['LaPlace']})
 
subplot(2,3,4);
imshow(prewitt);
xlabel({['Prewitt']})

subplot(2,3,5);
imshow(prewitt);
xlabel({['Sobel']})

subplot(2,3,6);
imshow(kirsch);
xlabel({['Kirsch']})