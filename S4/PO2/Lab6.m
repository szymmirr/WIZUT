im =imread('placek.png');
%imgray=rgb2gray(im);
subplot(1,2,1);
image(im);

subplot(1,2,2);
ImgVector = im(:);
%ImgVector = rot90(ImgVector);
%obr = mtx2vec(im);
%ImgVector = rehsape(im, 1, [100,100]);

image(ImgVector);

%https://www.mathworks.com/matlabcentral/newsreader/view_thread/172060