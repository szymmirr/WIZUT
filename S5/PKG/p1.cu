
#include <stdio.h>

#define  N   		1000
#define  BLOCK_SIZE	16

float 	   hArray[N];
float     *dArray;
int 	   blocks;


void prologue(void) {
	memset(hArray, 0, sizeof(hArray));
	for(int i = 0; i < N; i++) {
		hArray[i] =  i + 1;
	}		
   	cudaMalloc((void**)&dArray, sizeof(hArray));
   	cudaMemcpy(dArray, hArray, sizeof(hArray), cudaMemcpyHostToDevice);
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
    int	 devCnt;

    cudaGetDeviceCount(&devCnt);
    if(devCnt == 0) {
		perror("No CUDA devices available -- exiting.");
		return 1;
    }

    prologue();
    blocks = N / BLOCK_SIZE;
    if(N % BLOCK_SIZE)
		blocks++;
    pow3<<<blocks, BLOCK_SIZE>>>(dArray);
    cudaThreadSynchronize();
    epilogue();
    return 0;
}
