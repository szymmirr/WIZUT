#include <stdio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
using namespace std;

#define BLOCK_SIZE 78
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

	delete[] A.elements;
	delete[] B.elements;
	delete[] C.elements;
	return 0;
}
