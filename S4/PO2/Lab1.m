im=imread('kierowca.png');
[im,map]=imread('kierowca.png');
imgray=rgb2gray(im);
subplot(2,3,1);
imshow(imgray);
jasnosc = mean2(imgray);
kontrast = max(imgray(:)) - min(imgray(:));
xlabel({['Jasnoœæ: '],[num2str(jasnosc)],['Kontrast: ',num2str(kontrast)]})
imdouble=im2double(imgray);

subplot(2,3,2);
imadd=imgray+50;
imshow(imadd);
jasnosc = mean2(imadd);
kontrast = max(imadd(:)) - min(imadd(:));
xlabel({['Dodawanie sta³ej: '],[num2str(jasnosc)],['Kontrast: ',num2str(kontrast)]})

subplot(2,3,3);
immul=imgray*2;
imshow(immul);
jasnosc = mean2(immul);
kontrast = max(immul(:)) - min(immul(:));
xlabel({['Mno¿enie przez sta³¹: '],[num2str(jasnosc)],['Kontrast: ',num2str(kontrast)]})

subplot(2,3,4);
impot=power(imdouble, 1.5);
imshow(impot);
jasnosc = mean2(impot);
kontrast = max(impot(:)) - min(impot(:));
xlabel({['Potêgowanie: '],[num2str(jasnosc)],['Kontrast: ',num2str(kontrast)]})

subplot(2,3,5);
imsqrt=sqrt(imdouble);
imshow(imsqrt);
jasnosc = mean2(imsqrt);
kontrast = max(imsqrt(:)) - min(imsqrt(:));
xlabel({['Pierwiastkowanie: '],[num2str(jasnosc)],['Kontrast: ',num2str(kontrast)]})

subplot(2,3,6);
imlog=log(imdouble+1);
imshow(imlog);
jasnosc = mean2(imlog);
kontrast = max(imlog(:)) - min(imlog(:));
xlabel({['Logarytmowanie: '],[num2str(jasnosc)],['Kontrast: ',num2str(kontrast)]})