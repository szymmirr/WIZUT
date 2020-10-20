#include <complex>
#include <iostream>
#include <valarray>

const double PI = 3.141592653589793238460;

typedef std::complex<double> Complex;
typedef std::valarray<Complex> CArray;

// Cooley–Tukey FFT (in-place, divide-and-conquer)
// Higher memory requirements and redundancy although more intuitive
void fft(CArray& x)
{
    const size_t N = x.size();
    if (N <= 1) return;

    // divide
    CArray even = x[std::slice(0, N/2, 2)];
    CArray  odd = x[std::slice(1, N/2, 2)];

    // conquer
    fft(even);
    fft(odd);

    // combine
    for (size_t k = 0; k < N/2; ++k)
    {
        Complex t = std::polar(1.0, -2 * PI * k / N) * odd[k];
        x[k    ] = even[k] + t;
        x[k+N/2] = even[k] - t;
    }
}

int main()
{
    Complex z[60] = {};
    int fs = 1024;
    int T = 1;
    for(int n=0;n<60;n++)
    {
        z[n]=sin(200*M_PI*n/fs)+0.5*sin(350*M_PI*n/fs);
    }
    CArray data(z, 60);

    // forward fft
    fft(data);

    //std::cout << "fft" << std::endl;
    for (int i = 0; i < 60; ++i)
    {
        //std::cout << data[i] << std::endl;
        std::cout << abs(data[i]) << std::endl;
    }

    return 0;
}
