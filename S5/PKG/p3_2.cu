#include <stdio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
using namespace std;

// definiujemy rozmiar problemu i rozmiar bloku
#define NUMBER_OF_ARRAY_ELEMENTS 32
#define N_THREADS_PER_BLOCK 32
// funkcja powiększa o jeden każdy element tablicy a przechowywanej w
// pamięci hosta
void incrementArrayOnHost(float *a, int N)
{
 int i;
 for (i=0; i < N; i++)
a[i] = a[i]+1.f;
}
// kernel powiększa o jeden element tablicy przypadający na
// wykonujący go wątek
__global__ void incrementArrayOnDevice(float *a, int N)
{
 int idx = blockIdx.x * blockDim.x + threadIdx.x;
 if (idx < N)
a[idx] = a[idx]+1.f;
}

// funkcja pomocnicza (dla miłośników programowania defensywnego)
void checkCUDAError(const char *msg)
{
 cudaError_t err = cudaGetLastError();
 if( cudaSuccess != err) {
 fprintf(stderr, "Cuda error: %s: %s.\n", msg, cudaGetErrorString(err) );
 exit(EXIT_FAILURE);
 }
}

#define BLOCK_SIZE 64
//78 max
// Macierze są pamiętane wierszami, a więc:
// M(row, col) = *(M.elements + row * M.width + col)
typedef struct {
int width;
int height;
int stride;
float *elements;
} Matrix;
// funkcja do odczytywania wartości elementu wskazanej macierzy
__device__ float GetElement(const Matrix A, int row, int col)
{
return A.elements[row * A.stride + col];
}
// funkcja do zapisywania wartości elementu wskazanej macierzy
__device__ void SetElement(Matrix A, int row, int col, float value)
{
A.elements[row * A.stride + col] = value;
}

// wykreowanie opisu podmacierzy o rozmiarze BLOCK_SIZExBLOCK_SIZE, która
// ulokowana jest col podmacierzy w prawo i row podmacierzy w dół
// licząc od lewego wierzchołka danej macierzy
__device__ Matrix GetSubMatrix(Matrix A, int row, int col)
{
Matrix Asub;
Asub.width = BLOCK_SIZE;
Asub.height = BLOCK_SIZE;
Asub.stride = A.stride;
Asub.elements = &A.elements[A.stride * BLOCK_SIZE * row+ BLOCK_SIZE * col];
return Asub;
}


__global__ void MatMulKernel(const Matrix, const Matrix, Matrix);
void MatMul(const Matrix A, const Matrix B, Matrix C)
{
Matrix d_A;
d_A.width = d_A.stride = A.width;
d_A.height = A.height;
size_t size = A.width * A.height * sizeof(float);
cudaMalloc((void **)&d_A.elements, size);
cudaMemcpy(d_A.elements, A.elements, size,cudaMemcpyHostToDevice);
Matrix d_B;
d_B.width = d_B.stride = B.width;
d_B.height = B.height;
size = B.width * B.height * sizeof(float);
cudaMalloc((void **)&d_B.elements, size);
cudaMemcpy(d_B.elements, B.elements, size,cudaMemcpyHostToDevice);
Matrix d_C;
d_C.width = d_C.stride = C.width; d_C.height = C.height;
size = C.width * C.height * sizeof(float);
cudaMalloc((void **)&d_C.elements, size);
dim3 dimBlock(BLOCK_SIZE, BLOCK_SIZE);
dim3 dimGrid(B.width / dimBlock.x, A.height / dimBlock.y);
clock_t begin,end;
double time_spent;
begin = clock();


MatMulKernel<<<dimGrid, dimBlock>>>(d_A, d_B, d_C);

end = clock();
time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
cout<<time_spent<<" czas GPU"<<endl;

cudaMemcpy(C.elements, d_C.elements, size, cudaMemcpyDeviceToHost);

cudaFree(d_A.elements);
cudaFree(d_B.elements);
cudaFree(d_C.elements);
}

__global__ void MatMulKernel(Matrix A, Matrix B, Matrix C)
{
// ustalenie numeru wiersza i kolumny wewnątrz bloku
int blockRow = blockIdx.y;
int blockCol = blockIdx.x;
// każdy blok oblicza jedną podmacierz Csub macierzy C
Matrix Csub = GetSubMatrix(C, blockRow, blockCol);
// każdy wątek oblicza jeden element Csub akumulując wynik w Cvalue
float Cvalue = 0;
// ustalenie numeru wiersza i kolumny wewnątrz wątku
int row = threadIdx.y;
int col = threadIdx.x;
// iterujemy wszystkie podmacierze A i B, które
// są potrzebne do obliczenia Csub – mnożymy ze sobą każdą parę
// podmacierzy i akumulujemy wynik
for(int m = 0; m < (A.width / BLOCK_SIZE); ++m) {
// kreujemy podmacierz Asub macierzy A
Matrix Asub = GetSubMatrix(A, blockRow, m);
// kreujemy podmacierz Bsub macierzy B
Matrix Bsub = GetSubMatrix(B, m, blockCol);
// deklarujemy obszar pamięci dzielonej dla podmacierzy Asub i Bsub
__shared__ float As[BLOCK_SIZE][BLOCK_SIZE];
__shared__ float Bs[BLOCK_SIZE][BLOCK_SIZE];
// załaduj Asub i Bsub z pamięci globalnej do dzielonej
// (każdy wątek ładuje jeden element z każdej podmacierzy)
As[row][col] = GetElement(Asub, row, col);
Bs[row][col] = GetElement(Bsub, row, col);
// poczekajmy, aż wszystkie dane zostaną skopiowane
__syncthreads();
// mnożymy Asub i Bsub
for (int e = 0; e < BLOCK_SIZE; ++e)
Cvalue += As[row][e] * Bs[e][col];
// poczekajmy, aż obliczenia zostaną zakończone zanim zabierzemy
// się za przetwarzanie następnej podmacierzy
__syncthreads();
}
// odsyłamy obliczone Cvalue do pamięci urządzenia
SetElement(Csub, row, col, Cvalue);
}

__global__ void MatMulKernel2(float *A, float *B, float *C)
{
// ustalenie numeru wiersza i kolumny wewnątrz bloku
int blockRow = blockIdx.y;
int blockCol = blockIdx.x;
// każdy blok oblicza jedną podmacierz Csub macierzy C
float Csub = GetSubMatrix(C, blockRow, blockCol);
// każdy wątek oblicza jeden element Csub akumulując wynik w Cvalue
float Cvalue = 0;
// ustalenie numeru wiersza i kolumny wewnątrz wątku
int row = threadIdx.y;
int col = threadIdx.x;
// iterujemy wszystkie podmacierze A i B, które
// są potrzebne do obliczenia Csub – mnożymy ze sobą każdą parę
// podmacierzy i akumulujemy wynik
for(int m = 0; m < ((NUMBER_OF_ARRAY_ELEMENTS/2) / BLOCK_SIZE); ++m) {
// kreujemy podmacierz Asub macierzy A
float Asub = GetSubMatrix(A, blockRow, m);
// kreujemy podmacierz Bsub macierzy B
float Bsub = GetSubMatrix(B, m, blockCol);
// deklarujemy obszar pamięci dzielonej dla podmacierzy Asub i Bsub
__shared__ float As[BLOCK_SIZE][BLOCK_SIZE];
__shared__ float Bs[BLOCK_SIZE][BLOCK_SIZE];
// załaduj Asub i Bsub z pamięci globalnej do dzielonej
// (każdy wątek ładuje jeden element z każdej podmacierzy)
As[row][col] = GetElement(Asub, row, col);
Bs[row][col] = GetElement(Bsub, row, col);
// poczekajmy, aż wszystkie dane zostaną skopiowane
__syncthreads();
// mnożymy Asub i Bsub
for (int e = 0; e < BLOCK_SIZE; ++e)
Cvalue += As[row][e] * Bs[e][col];
// poczekajmy, aż obliczenia zostaną zakończone zanim zabierzemy
// się za przetwarzanie następnej podmacierzy
__syncthreads();
}
// odsyłamy obliczone Cvalue do pamięci urządzenia
SetElement(Csub, row, col, Cvalue);
}

int main(int argc, char *argv[])
{
	int mode=0;
	char teges[40]={};
	if(argc<2)
	{
		cout<<"nie podano argumentu: --copy, --map lub --auto"<<endl;
		return 0;
	}
strcpy(teges, argv[1]);
  if(strcmp (teges, "--copy")==0)
  {
    cout<<"copy"<<endl;
	mode=1;
  }
  else if(strcmp (teges, "--map")==0)
  {
    cout<<"map"<<endl;
	mode=2;
  }
  else if(strcmp (teges, "--auto")==0)
  {
    cout<<"auto"<<endl;
	mode=3;
  }
  else
  {
    cout<<"nie podano argumentu: --copy, --map lub --auto"<<endl;
	return 0;
  }
	cout<<fixed;
	if (mode==3)
	{
		mode=2;
		#if CUDART_VERSION < 2020
		#error "To urzadzenie nie wspiera mapowania pamieci ;(\n"
		mode=1;
		#endif
	}
	if (mode==1)
	{
		Matrix A;
		A.width = 40000;
		A.height = 40000;
		A.elements = new float[A.width*A.height];
		Matrix B;
		B.width = 40000;
		B.height = 40000;
		B.elements = new float[B.width*B.height];

		for (int i=0; i< A.width*A.height; i++)
		{
			A.elements[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		}

		for (int i=0; i< B.width*B.height; i++)
		{
			B.elements[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		}

		Matrix C;
		C.width = 40000;
		C.height = 40000;
		 C.elements = new float[C.width*C.height];
		for (int i=0; i< C.width*C.height; i++)
		{
			C.elements[i] = 0;
		}

		MatMul (A, B, C);
		delete[] A.elements;
		delete[] B.elements;
		delete[] C.elements;
	}

	if (mode==2)
	{
		float *a_m_A; // wskaźnik do pamięci hosta
		 float *a_d_A; // wskaźnik do zamapowanej pamięci urządzenia
		float *a_m_B; // wskaźnik do pamięci hosta
		 float *a_d_B; // wskaźnik do zamapowanej pamięci urządzenia
		float *a_m_C; // wskaźnik do pamięci hosta
		 float *a_d_C; // wskaźnik do zamapowanej pamięci urządzenia
		 int N = NUMBER_OF_ARRAY_ELEMENTS;
		size_t size = NUMBER_OF_ARRAY_ELEMENTS * sizeof(float);
		 cudaDeviceProp deviceProp;
		#if CUDART_VERSION < 2020
		#error "To urzadzenie nie wspiera mapowania pamieci ;(\n"
		mode=1;
		#endif
		 // Pobierz własności i sprawdź, czy urządzenie #0 wspiera mapowanie
		 cudaGetDeviceProperties(&deviceProp, 0);
		 checkCUDAError("cudaGetDeviceProperties");
		 if(!deviceProp.canMapHostMemory) {
		 fprintf(stderr, "Urzadzenie %d nie wspiera mapowania pamieci ;(\n", 0);
		 exit(EXIT_FAILURE);
		}
			// przygotuj urządzenie do mapowania pamięci
		 cudaSetDeviceFlags(cudaDeviceMapHost);
		 checkCUDAError("cudaSetDeviceFlags");
		 // przydziel pamięć mapowaną
		 cudaHostAlloc((void**)&a_m_A, size, cudaHostAllocMapped);
		cudaHostAlloc((void**)&a_m_B, size, cudaHostAllocMapped);
		cudaHostAlloc((void**)&a_m_C, size, cudaHostAllocMapped);
		 checkCUDAError("cudaHostAllocMapped");
		 // pobierz wskaźnik na pamięć dzielona użyteczny dla urządzenia
		 cudaHostGetDevicePointer((void**)&a_d_A, (void*)a_m_A, 0);
		cudaHostGetDevicePointer((void**)&a_d_B, (void*)a_m_B, 0);
		cudaHostGetDevicePointer((void**)&a_d_C, (void*)a_m_C, 0);
		 checkCUDAError("cudaHostGetDevicePointer");
		 // inicjacja danych hosta
		 for (int i=0; i<N; i++)
		{
			a_m_A[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		}
		for (int i=0; i<N; i++)
		{
			a_m_B[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
		}
		for (int i=0; i<N; i++)
		{
			a_m_C[i] = 0;
		}

		 // przygotowanie konfiguracji dla dla odpalenia wątków
		 int blockSize = N_THREADS_PER_BLOCK;
		 int nBlocks = N / blockSize + (N % blockSize > 0 ? 1 : 0);
		// odpalenie wątku
		 //incrementArrayOnDevice <<< nBlocks, blockSize >>> (a_d, N);
		clock_t begin,end;
		double time_spent;
		begin = clock();
		MatMulKernel2 <<< nBlocks, blockSize >>> (a_d_A, a_d_B, a_d_C);
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		cout<<time_spent<<" czas GPU z mapowaniem"<<endl;
		 checkCUDAError("incrementArrayOnDevice");
		 cudaThreadSynchronize();
		 checkCUDAError("cudaThreadSynchronize");
		for (int i=0; i< NUMBER_OF_ARRAY_ELEMENTS; i++)
		{
			//cout << a_m_C[i] << endl;
		}
		 cudaFreeHost(a_m_A); // zwalniamy pamięć dzieloną
		cudaFreeHost(a_m_B); // zwalniamy pamięć dzieloną
		cudaFreeHost(a_m_C); // zwalniamy pamięć dzieloną
		}
	return 0;
}
