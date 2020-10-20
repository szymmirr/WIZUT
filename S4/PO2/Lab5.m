im =imread('KOLKA_DO_ht.png');
imgray=rgb2gray(im);
[im,map]=imread('KOLKA_DO_ht.png');

subplot(2,2,1);
imshow(im);
xlabel('Oryginal');

subplot(2,2,2);
imshow(imgray);
xlabel('Szary');

BW1 = edge(imgray,'canny');
subplot(2,2,3);
imshow(BW1);
xlabel('Krawedzie');

subplot(2,2,4);
[centers, radii] = imfindcircles(imgray,[15 70],'ObjectPolarity','dark','Sensitivity',0.93)
[centers1, radii1] = imfindcircles(imgray,[50 130],'ObjectPolarity','bright','Sensitivity',0.93)
imshow(im);
h=viscircles(centers1,radii1);
j=viscircles(centers,radii);
n=numel(radii1);
n1=numel(radii);
kola=n+n1;
xlabel({['Wykryte kola: ',num2str(kola)]});
