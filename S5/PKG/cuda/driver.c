#include	<stdio.h>
#include	<assert.h> 
#include	<cuda.h>

#include 	"defines.h"

#define ALIGN_UP(offset, alignment)  (offset) = ((offset) + (alignment) - 1) & ~((alignment) - 1)

float    HostVect[N];

int main(int argc, char *argv[]) {

	int i;
	int blocks = N / BLK_SZ;
        if(N % BLK_SZ) blocks++;

        for(i = 0; i < N; i++)
                HostVect[i] = i;

	CUdevice	hDevice;
	CUcontext	hContext;
	CUmodule	hModule;
	CUfunction	hFunction;

	CALL( cuInit(0) );
	CALL( cuDeviceGet(&hDevice, 0) ); 	
	CALL( cuCtxCreate(&hContext, 0, hDevice) );
	CALL( cuModuleLoad(&hModule, "kernel.cubin") );
	CALL( cuModuleGetFunction(&hFunction, hModule, "IncVect") );

	CUdeviceptr DevVectIn, DevVectOut;

	CALL( cuMemAlloc(&DevVectIn, sizeof(HostVect)) );
	CALL( cuMemAlloc(&DevVectOut, sizeof(HostVect)) );

	CALL( cuMemcpyHtoD(DevVectIn, HostVect, sizeof(HostVect)) );

	CALL( cuFuncSetBlockShape(hFunction, BLK_SZ, 1, 1) );

	int 	offset = 0;
	void   *ptr;


	ptr = (void*)(size_t)DevVectIn;
	ALIGN_UP(offset, __alignof(ptr));
	CALL( cuParamSetv(hFunction, offset, &ptr, sizeof(ptr)) );
	offset += sizeof(ptr);

	ptr = (void*)(size_t)DevVectOut;
	ALIGN_UP(offset, __alignof(ptr));
	CALL( cuParamSetv(hFunction, offset, &ptr, sizeof(ptr)) );
	offset += sizeof(ptr);

	CALL( cuParamSetSize(hFunction, offset) );

	CALL( cuLaunchGrid(hFunction, blocks, 1) );

	CALL( cuMemcpyDtoH((void *) HostVect, DevVectOut, sizeof(HostVect)) );

	CALL( cuMemFree(DevVectIn) );
	CALL( cuMemFree(DevVectOut) );

	for(i = 0; i < N; i++)
                assert(HostVect[i] == i + 1);
	
	puts("done");
	return 0;
}

