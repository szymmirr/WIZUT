clc
clear all

%ilosc = 100;
pokolenia = 100;
pokolenie = 0;
min=Inf;
max=-Inf;
pc = 0.9;
pm = 0.05;
f = @(x) 2*(x^2)+1;
%ch = randi([0,1],ilosc,12);
C = 100;
items = [100, 40; 50, 35; 45, 18; 20, 4; 10, 10; 5, 2];
items_count = numel(items)/2;
ilosc = 2^items_count;
weight = items(1:1:end, 1);
worth = items(1:1:end, 2);
weight = reshape(weight.',1,[]);
worth = reshape(worth.',1,[]);
for i=1:ilosc
    weight = [weight;weight(end,:)];
    worth = [worth;worth(end,:)];
end
weight = reshape(weight.',1,[]);
worth = reshape(worth.',1,[]);
weight;
worth;
ch = randi([0,1],2^items_count,items_count);
ch = reshape(ch.',1,[]);
ch;
worth_max = 0;
weight_max = 0;
while 1
    pokolenie = pokolenie + 1;

    ocena = 0;
    waga = 0;
    oceny = (ilosc);
    next = items_count;
    ocen = 1;
    wag = 1;
    for i=1:numel(ch)
        i;
        ch(i);
        if ch(i)==1
            ocena;
            worth(i);
           ocena = ocena + worth(i);
           waga = waga + weight(i);
           ocena;
           if waga>C
                ocena=0;
           end
%             if ocena>worth_max
%                worth_max = ocena;
%                weight_max = waga;
%                wybrane = ch(i-items_count:i)
%             end
        end
        if i==next
            if ocena>worth_max
               worth_max = ocena;
               weight_max = waga;
               wybrane = ch(i-items_count+1:i);
            end
            oceny(ocen)=ocena;
            wagi(wag)=waga;
            ocen=ocen+1;
            wag=wag+1;
            ocena = 0;
            waga = 0;
            next=next+items_count;
        end
    end
    
    oceny;
    wagi;
    ilosc;
    numel(ch);
    items_count;
    worth_max;
    weight_max;


    for i=1:ilosc
       f(oceny(i));
       if min > f(oceny(i))
          min=f(oceny(i));
       end
    end
    min;
    
    for i=1:ilosc
       f(oceny(i));
       if max < f(oceny(i))
          max=f(oceny(i));
       end
    end
    max;


    if pokolenie==pokolenia
        break
    end


    fch = zeros(1,ilosc);
    for i=1:items_count
        %i*items_count
        fch(i) = sum(ch(i*items_count:i*items_count+items_count-1));
    end

    vch = zeros(1,ilosc);
    for i=1:ilosc
        vch(i) = (fch(i)/46)*100;
    end
    
    if sum(vch)<=0
       break 
    end
    R = randsample(1:ilosc, ilosc, true, vch);

    pkt=randi([1,11],1,(ilosc/2));

    Ch = zeros(ilosc,items_count);
    for i=1:ilosc
        rodi = R(i);
        od = rodi*items_count;
        do = rodi*items_count+items_count-1;
        vec = ch(od:do);
        mat = vec2mat(vec,items_count);
        Ch(i,:);
        Ch(i,:)=mat;
    end

    pc2=rand();
    if pc2 <= pc
        lulz=666;
    else
        lulz=777;
    end
    pc;
    pc2;
    
    ch=vec2mat(ch,items_count);
    for i=1:(ilosc/2)
        pc2=rand();
        if pc2 <= pc
            for j=pkt(i):items_count
                Ch((i*2)-1,j)=ch(R((i*2)),j);
                Ch((i*2),j)=ch(R((i*2)-1),j);
            end
        end
        pm2=rand();
        if pm2 <= pm
            mut = randi([1,items_count],1,1);
            if Ch((i*2)-1,mut) == 1
                Ch((i*2)-1,mut) = 0;
            else
                Ch((i*2)-1,mut) = 1;
            end
        end
        pm2=rand();
        if pm2 <= pm
            mut = randi([1,items_count],1,1);
            if Ch((i*2),mut) == 1
                Ch((i*2),mut) = 0;
            else
                Ch((i*2),mut) = 1;
            end
        end
    end
    
    ch;
    Ch;

    for i=1:ilosc
        fch = sum(Ch(i,:));
    end
    ch=Ch;
end
    wybrane2=[];
    worth_max
    weight_max
    for i=1:items_count
       if wybrane(i)==1
          wybrane2 = [wybrane2 i];
       end
    end
    wybrane2
