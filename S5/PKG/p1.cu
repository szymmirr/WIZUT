#include <stdio.h>
#include <time.h>
#include <iostream>
#include <iomanip>
using namespace std;
#define  N   		1000
#define  BLOCK_SIZE	1024

float 	   hArray[N];
float     *dArray;
float			hArray2[N];
float			dArray2[N];
int 	   blocks;


void prologue(void) {
	memset(hArray, 0, sizeof(hArray));
	for(int i = 0; i < N; i++) {
		hArray[i] =  i + 1;
	}
   	cudaMalloc((void**)&dArray, sizeof(hArray));
   	cudaMemcpy(dArray, hArray, sizeof(hArray), cudaMemcpyHostToDevice);
}

void cpu()
{
	memset(hArray2, 0, sizeof(hArray2));
	for(int i = 0; i < N; i++) {
		hArray2[i] =  i + 1;
	}
	for(int i = 0; i < N; i++) {
		dArray2[i] =  0;
	}
	for(int i = 0; i<N;i++)
	{
		dArray2[i] = hArray2[i] * hArray2[i] * hArray2[i] + hArray2[i] * hArray2[i] + hArray2[i];

	}
}

void epilogue(void) {
	cudaMemcpy(hArray, dArray, sizeof(hArray), cudaMemcpyDeviceToHost);
	cudaFree(dArray);
}


// Kernel
__global__ void pow3(float *A) {
	int x = blockDim.x * blockIdx.x + threadIdx.x;

    if(x < N)
	    A[x] = A[x] * A[x] * A[x] + A[x] * A[x] + A[x];
}

int main(int argc, char** argv)
{
		clock_t begin, end,begin2,end2;
		double time_spent;
		begin = clock();
		begin2 = clock();
		cout<<fixed;
		cout<<setprecision(6);

		int	 devCnt;

		cudaGetDeviceCount(&devCnt);
		if(devCnt == 0) {
		perror("No CUDA devices available -- exiting.");
		return 1;
		}

		prologue();
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

		cout<<"Transfer to device = " <<time_spent<<"s"<<endl;

		blocks = N / BLOCK_SIZE;
		if(N % BLOCK_SIZE)
		blocks++;
		pow3<<<blocks, BLOCK_SIZE>>>(dArray);
		cudaThreadSynchronize();

		begin = clock();
		epilogue();
		end = clock();
		time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		cout<<"Transfer from device = " <<time_spent<<"s"<<endl;


end2 = clock();
time_spent = (double)(end2 - begin2) / CLOCKS_PER_SEC;
		cout <<"GPU time = "<<time_spent << "s"<<endl;
begin = clock();
cpu();
end = clock();
time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

		cout << "CPU time = " <<time_spent<<"s"<<endl;
    return 0;
}

