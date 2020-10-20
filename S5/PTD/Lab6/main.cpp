#include <iostream>
using namespace std;
int main()
{
    long long int x1,x2,x3,x4,x5,x6,x7;
    for (int i=0;i<180;i++)
    {
        cin >> x7 >> x6 >> x5 >> x3;
        if(x3==1&&x5==1&&x7==1)
        {
            x1=1;
        }
        else if(x3==0&&x5==0&&x7==0)
        {
            x1=1;
        }
        else
        {
            x1=0;
        }

        if(x3==1&&x6==1&&x7==1)
        {
            x2=1;
        }
        else if(x3==0&&x6==0&&x7==0)
        {
            x2=1;
        }
        else
        {
            x2=0;
        }

        if(x5==1&&x6==1&&x7==1)
        {
            x4=1;
        }
        else if(x5==0&&x6==0&&x7==0)
        {
            x4=1;
        }
        else
        {
            x4=0;
        }
        cout << "Slowo zakodowane wyslane: " << x7 << x6 << x5 << x4 << x3 << x2 << x1 << endl;

        int x1o,x2o,x3o,x4o,x5o,x6o,x7o;
        x1o=x1;x2o=x2;x3o=x3;x4o=x4;x5o=x5;x6o=x6;x7o=x7;

        x5o=0; //wprowadzenie bledu

        cout << "Slowo zakodowane odebrane: " << x7o << x6o << x5o << x4o << x3o << x2o << x1o << endl;

        /*int x1p,x2p,x4p;
        if(x3o==1&&x5o==1&&x7o==1)
        {
            x1p=1;
        }
        else if(x3o==0&&x5o==0&&x7o==0)
        {
            x1p=1;
        }
        else
        {
            x1p=0;
        }

        if(x3o==1&&x6o==1&&x7o==1)
        {
            x2p=1;
        }
        else if(x3o==0&&x6o==0&&x7o==0)
        {
            x2p=1;
        }
        else
        {
            x2p=0;
        }

        if(x5o==1&&x6o==1&&x7o==1)
        {
            x4p=1;
        }
        else if(x5o==0&&x6o==0&&x7o==0)
        {
            x4p=1;
        }
        else
        {
            x4p=0;
        }

        cout << "x1p " << x1p << endl;
        cout << "x2p " << x2p << endl;
        cout << "x4p " << x4p << endl;
        int x1k,x2k,x4k;
        if(x1o==1&&x1p==1)
        {
            x1k=1;
        }
        else if(x1o==0&&x1p==0)
        {
            x1k=1;
        }
        else
        {
            x1k=0;
        }

        if(x2o==1&&x2p==1)
        {
            x2k=1;
        }
        else if(x2o==0&&x2p==0)
        {
            x2k=1;
        }
        else
        {
            x2k=0;
        }

        if(x4o==1&&x4p==1)
        {
            x4k=1;
        }
        else if(x4o==0&&x4p==0)
        {
            x4k=1;
        }
        else
        {
            x4k=0;
        }

        int S=x1k+(x2k*2)+(x4k*4);
        cout << "S: " << S;*/

        int bit1=0,bit2=0,bit3=0;
        if(x7o==1)
        {
            bit1+=1;
            bit2+=1;
            bit3+=1;
        }
        if(x6o==1)
        {
            bit1+=1;
            bit2+=1;
        }
        if(x5o==1)
        {
            bit1+=1;
            bit3+=1;
        }
        if(x4o==1)
        {
            bit1+=1;
        }
        if(x3o==1)
        {
            bit2+=1;
            bit3+=1;
        }
        if(x2o==1)
        {
            bit2+=1;
        }
        if(x1o==1)
        {
            bit3+=1;
        }

        int bit1p=0,bit2p=0,bit3p=0;
        if(bit1%2!=0)
        {
            bit1p=1;
        }
        if(bit2%2!=0)
        {
            bit2p=1;
        }
        if(bit3%2!=0)
        {
            bit3p=1;
        }

        int pozycja=0;
        if(bit1p==1&&bit2p==1&&bit3p==1)
        {
            pozycja=7;
        }
        if(bit1p==1&&bit2p==1&&bit3p==0)
        {
            pozycja=6;
        }
        if(bit1p==1&&bit2p==0&&bit3p==1)
        {
            pozycja=5;
        }
        if(bit1p==1&&bit2p==0&&bit3p==0)
        {
            pozycja=4;
        }
        if(bit1p==0&&bit2p==1&&bit3p==1)
        {
            pozycja=3;
        }
        if(bit1p==0&&bit2p==1&&bit3p==0)
        {
            pozycja=2;
        }
        if(bit1p==0&&bit2p==0&&bit3p==1)
        {
            pozycja=1;
        }
        cout << "Blad na pozycji " << pozycja << endl;
        if(pozycja==7)
        {
            if(x7o==1)x7o=0;
            else x7o=1;
        }
        if(pozycja==6)
        {
            if(x6o==1)x6o=0;
            else x6o=1;
        }
        if(pozycja==5)
        {
            if(x5o==1)x5o=0;
            else x5o=1;
        }
        if(pozycja==4)
        {
            if(x4o==1)x4o=0;
            else x4o=1;
        }
        if(pozycja==3)
        {
            if(x3o==1)x3o=0;
            else x3o=1;
        }
        if(pozycja==2)
        {
            if(x2o==1)x2o=0;
            else x2o=1;
        }
        if(pozycja==1)
        {
            if(x1o==1)x1o=0;
            else x1o=1;
        }
        cout << "Slowo odszyfrowane i skorygowane: " << x7o << x6o << x5o << x3o;
    }

    return 0;
}
