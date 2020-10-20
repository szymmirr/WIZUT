figure(1);
im=imread('kierowca.png');
[im,map]=imread('kierowca.png');
imgray=rgb2gray(im);
subplot(4,2,1);
imshow(imgray);
xlabel({['Orygina³']})
imdouble=im2double(imgray);

subplot(4,2,2);
imadd=imgray+50;
imhist(imdouble);
xlabel({[],[],['Histogram orygina³u']})

subplot(4,2,3);
obr1=imdouble-min(min(imdouble));
obr2=obr1./max(max(obr1));
imshow(obr2);
xlabel({['Rozciagniecie']})

subplot(4,2,4);
obr1=imdouble-min(min(imdouble));
obr2=obr1./max(max(obr1));
imhist(obr2);
xlabel({[],[],['Rozciagniecie']})

subplot(4,2,5);
imshow(histeq(imdouble));
xlabel({['Wyrownanie']})

subplot(4,2,6);
imhist(histeq(imdouble));
xlabel({[],[],['Wyrownanie']})

%subplot(4,2,7);
%Istr = round((imdouble-min(min(imdouble)))* ((max(max(imdouble))-min(min(imdouble)))/(max(max(imdouble))-min(min(imdouble)))));
%imshow(Istr);
%xlabel({['Wyrownanie']})

%subplot(4,2,8);
%Istr = round((imdouble-min(min(imdouble)))* ((max(max(imdouble))-min(min(imdouble)))/(max(max(imdouble))-min(min(imdouble)))));
%imhist(Istr);
%xlabel({['Wyrownanie']})

figure(2);
%subplot(4,2,1);
%imshow(imdouble^2);
%xlabel({[],[],['Potegowanie']})

%subplot(4,2,2);
%imhist(imdouble^2);
%xlabel({[],[],['Potegowanie']})

subplot(4,2,3);
imsqrt=sqrt(imdouble);
imshow(imsqrt);
xlabel({[],[],['Pierwiastkowanie']})

subplot(4,2,4);
imhist(histeq(imsqrt));
xlabel({[],[],['Pierwiastkowanie']})

subplot(4,2,5);
imlog=log(imdouble+1);
imshow(histeq(imlog));
xlabel({[],[],['Logarytmowanie']})

subplot(4,2,6);
imlog=log(imdouble+1);
imhist(histeq(imlog));
xlabel({[],[],['Logarytmowanie']})