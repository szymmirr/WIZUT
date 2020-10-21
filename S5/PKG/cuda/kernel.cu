#include "defines.h"

extern "C" __global__ void IncVect(float *Tin, float *Tout) {
	int x = blockDim.x * blockIdx.x + threadIdx.x;
	if(x < N)
		Tout[x] = Tin[x] + 1;
}

