#include <stdio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
using namespace std;

// Macierze są pamiętane wierszami, a więc:
// M(row, col) = *(M.elements + row * M.width + col)
typedef struct {
	int width;
	int height;
	float *elements;
} Matrix;

// definiujemy rozmiar bloku wątków:
#define BLOCK_SIZE 78

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
	int row = blockIdx.y*blockDim.y + threadIdx.y;
	int col = blockIdx.x*blockDim.x +threadIdx.x;

	for (int e = 0; e < A.width; ++e)
	{
		Cvalue += A.elements[row * A.width + e]* B.elements[e * B.width + col];
	}
	C.elements[row * C.width + col] = Cvalue;
}

int main(int argc, char** argv)
{
	cout<<fixed;
	Matrix A;
	A.width = 42000;
	A.height = 42000;
	A.elements = new float[A.width*A.height];
	Matrix B;
	B.width = 42000;
	B.height = 42000;
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
	C.width = 42000;
	C.height = 42000;
	C.elements = new float[C.width*C.height];
	for (int i=0; i< C.width*C.height; i++)
	{
		C.elements[i] = 0;
	}

	MatMul (A, B, C);

	for (int i=0; i< C.width*C.height; i++)
	{
		C.elements[i] = 0;
	}
	cpu (A,B,C);
	delete[] A.elements;
	delete[] B.elements;
	delete[] C.elements;
	return 0;
}
