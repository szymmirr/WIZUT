im=imread('rozmazany.png');
%imgray=rgb2gray(im);
im2=imread('ostry.png');
imgray2=rgb2gray(im2);
imdouble=im2double(im);
imdouble2=im2double(imgray2);
%glcm = graycomatrix(imdouble/max(imdouble(:)));
%glcm = graycomatrix(imdouble,'Offset',[2 0])
[glcm, SI] = graycomatrix(imdouble,'NumLevels',255,'GrayLimits',[]);
[glcm2, SI] = graycomatrix(imdouble2,'NumLevels',255,'GrayLimits',[]);
%glcm = graycomatrix(glcm, 'offset', [0 1], 'Symmetric', true)
K=mat2gray(glcm)
reversedImg = 1-K;
K2=mat2gray(glcm2)
reversedImg2 = 1-K2;

subplot(2,2,1);
imshow(imdouble);
xlabel({['Rozmazany']})
%imdouble=im2double(imgray);

subplot(2,2,2);
%imshow(im2);
%hist(glcm);
imshow(reversedImg);
%hist(graycomatrix(glcm, 'offset', [0 1], 'Symmetric', true));
xlabel({['Macierz']})
%imshow(imgray2);

subplot(2,2,3);
imshow(imdouble2);
xlabel({['Ostry']})

subplot(2,2,4);
imshow(reversedImg2);
%hist(graycomatrix(glcm, 'offset', [0 1], 'Symmetric', true));
xlabel({['Macierz']})
