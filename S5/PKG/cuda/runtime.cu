#include <assert.h>
#include <stdio.h>

#define		N		1000
#define		BLOCK_SIZE	16

float		HostVect[N];
float	       *DevVectIn, *DevVectOut;
int		blocks;

__global__ void IncVect(float *Tin, float *Tout) {
	int x = blockDim.x * blockIdx.x + threadIdx.x;
	if(x < N)
		Tout[x] = Tin[x] + 1;
}

int main(int argc, char *argv[]) {

	for(int i = 0; i < N; i++)
		HostVect[i] = i;
	cudaMalloc((void **) &DevVectIn, sizeof(HostVect));
	cudaMalloc((void **) &DevVectOut, sizeof(HostVect));
	cudaMemcpy(DevVectIn, HostVect, sizeof(HostVect), cudaMemcpyHostToDevice);
	blocks = N / BLOCK_SIZE;
	if(N % BLOCK_SIZE) blocks++;
	IncVect<<<blocks, BLOCK_SIZE>>>(DevVectIn, DevVectOut);
	cudaThreadSynchronize();
	cudaMemcpy(HostVect, DevVectOut, sizeof(HostVect), cudaMemcpyDeviceToHost);
	cudaFree(DevVectIn);
	cudaFree(DevVectOut);
	for(int i = 0; i < N; i++)
		assert(HostVect[i] == i + 1);
	puts("done");
	return 0;
}

