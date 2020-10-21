#include <stdio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <assert.h>
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

// Macierze są pamiętane wierszami, a więc:
// M(row, col) = *(M.elements + row * M.width + col)
typedef struct {
	int width;
	int height;
	float *elements;
} Matrix;

// definiujemy rozmiar bloku wątków:
#define BLOCK_SIZE 3200

// prototyp funkcji mnożącej (kernela)
__global__ void MatMulKernel(const Matrix, const Matrix, Matrix);


// Zakładamy (dla uproszczenia rozważań), że wymiary macierzy są
// całkowitymi wielokrotnościami wartości BLOCK_SIZE
void cpu(const Matrix A, const Matrix B, Matrix C)
{
	clock_t begin,end;
	double time_spent;
	begin = clock();
	for(int i = 0; i < A.height; i++)
	 for(int j = 0; j < B.width; j++)
	 {
		 float s = 0;
		 for(int k = 0; k < B.height; k++)
		 {
			 	s += A.elements[i * A.width + k] * B.elements[k * A.width + j];
		 }
		 C.elements[i * C.width + j] = s;
	 }
	 end = clock();
 	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
 	cout<<time_spent<<" czas CPU"<<endl;
	 cout<<"wynik cpu"<<endl;
	 for (int i=0; i< C.width*C.height; i++)
 	{
 		//cout << C.elements[i] << endl;
 	}
}
// Funkcja mnożąca
void MatMul(const Matrix A, const Matrix B, Matrix C)
{
	// kopiujemy macierze A i B to globalnej pamięci urządzenia
	// najpierw A
	Matrix d_A;
	d_A.width = A.width;
	d_A.height = A.height;
	size_t size = A.width * A.height * sizeof(float);
	cudaMalloc((void **)&d_A.elements, size);
	cudaMemcpy(d_A.elements, A.elements, size, cudaMemcpyHostToDevice);
	// potem B
	Matrix d_B;
	d_B.width = B.width;
	d_B.height = B.height;
	size = B.width * B.height * sizeof(float);
	cudaMalloc((void **)&d_B.elements, size);
	cudaMemcpy(d_B.elements, B.elements, size,cudaMemcpyHostToDevice);

	// przydzielamy macierz C w globalnej pamięci urządzenia
	Matrix d_C;
	d_C.width = C.width;
	d_C.height = C.height;
	size = C.width * C.height * sizeof(float);
	cudaMalloc((void **)&d_C.elements, size);
	// preparujemy środowisko i wywołujemy kernel
	dim3 dimBlock(BLOCK_SIZE, BLOCK_SIZE);
	dim3 dimGrid(B.width / dimBlock.x, A.height / dimBlock.y);
	//czas
	clock_t begin,end;
	double time_spent;
	begin = clock();

	MatMulKernel<<<dimGrid, dimBlock>>>(d_A, d_B, d_C);

	end = clock();
	time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
	cout<<time_spent<<" czas GPU"<<endl;

	// odbieramy obliczoną macierz C z pamięci globalnej urządzenia
	cudaMemcpy(C.elements, d_C.elements, size, cudaMemcpyDeviceToHost);
	// zwalniamy pamięć
	cudaFree(d_A.elements);
	cudaFree(d_B.elements);
	cudaFree(d_C.elements);
}

// kernel odpowiedzialny za wymnożenie macierzy
__global__ void MatMulKernel(Matrix A, Matrix B, Matrix C)
{
	// każdy wątek oblicza jeden element macierzy C
	// akumulując wynik w zmiennej Cvalue
	float Cvalue = 0;
//printf ("cvalue %d \n", Cvalue);
	int row = blockIdx.y*blockDim.y + threadIdx.y;
	int col = blockIdx.x*blockDim.x +threadIdx.x;
	//cuPrintf("cvalue %d /n", Cvalue);

	for (int e = 0; e < A.width; ++e)
	{
		Cvalue += A.elements[row * A.width + e]* B.elements[e * B.width + col];
	}

//	printf ("cvalue %f \n", Cvalue);
	C.elements[row * C.width + col] = Cvalue;
}

__global__ void MatMulKernel2(float *A, float *B, float *C)
{
	// każdy wątek oblicza jeden element macierzy C
	// akumulując wynik w zmiennej Cvalue
	float Cvalue = 0;
	int row = blockIdx.y*blockDim.y + threadIdx.y;
	int col = blockIdx.x*blockDim.x +threadIdx.x;

	for (int e = 0; e < NUMBER_OF_ARRAY_ELEMENTS/2; ++e)
	{
		Cvalue += A[row * (NUMBER_OF_ARRAY_ELEMENTS/2) + e]* B[e * (NUMBER_OF_ARRAY_ELEMENTS/2) + col];
	}

	//printf ("cvalue %f \n", Cvalue);
	C[row * (NUMBER_OF_ARRAY_ELEMENTS/2) + col] = Cvalue;
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
		A.width = 32;
		A.height = 32;
		A.elements = new float[A.width*A.height];
		Matrix B;
		B.width = 32;
		B.height = 32;
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
		C.width = 32;
		C.height = 32;
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



