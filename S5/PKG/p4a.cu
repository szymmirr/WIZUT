#include <stdio.h>
#include <fstream>
#include <iostream>
#include <time.h>
using namespace std;

#define  N   		1048576
#define  BLOCK_SIZE	1024

unsigned char 	   hArray[N];
unsigned char     *dArray;
float			hArray2[N];
float			dArray2[N];
long long int 	   blocks;

void epilogue(void) {
	cudaMemcpy(hArray, dArray, sizeof(hArray), cudaMemcpyDeviceToHost);
	cudaFree(dArray);
}

// Kernel
__global__ void pow3(unsigned char *A) {
	int x = blockDim.x * blockIdx.x + threadIdx.x;

    //if(x < N)
	    //A[x] = A[x] * A[x] * A[x] + A[x] * A[x] + A[x];

	double color1 = A[x];
	double color2 = A[x+1];
	double color3 = A[x+2];
	if(x < N)
	{
    	A[x]=(color1+color2+color3)/3;
    	//A[x+1]=(color1+color2+color3)/3;
    	//A[x+2]=(color1+color2+color3)/3;
		//printf("%f/n",A[x]);
	}
}

struct unpacked {
        char c;
        long l;
};

struct packed {
        char c;
        long l;
} __attribute__ ((packed));


unsigned char* readBMP(char* filename)
{
	clock_t begin, end,begin2,end2;
	double time_spent;
    int i;
    FILE* f = fopen(filename, "rb");
    unsigned char info[54];
    fread(info, sizeof(unsigned char), 54, f); // read the 54-byte header

    // extract image height and width from header
    int width = *(int*)&info[18];
    int height = *(int*)&info[22];

    int size = 3 * width * height;
    unsigned char* data = new unsigned char[size]; // allocate 3 bytes per pixel
    fread(data, sizeof(unsigned char), size, f); // read the rest of the data at once
	unsigned char* data2 = new unsigned char[size]; // allocate 3 bytes per pixel
    fread(data2, sizeof(unsigned char), size, f); // read the rest of the data at once
    fclose(f);

	memset(hArray, 0, sizeof(hArray));
	for(long long int i = 0; i < N; i++) {
		hArray[i] =  data[i];
	}

begin = clock();
    for(i = 0; i < size; i ++)
    {
		double color1 = data[i];
		double color2 = data[i+1];
		double color3 = data[i+2];
        //data[i]=(color1*0.299)+(color2*0.587)+(color3*0.114);
        //data[i+1]=(color1*0.299)+(color2*0.587)+(color3*0.114);
        //data[i+2]=(color1*0.299)+(color2*0.587)+(color3*0.114);
		data[i]=(color1+color2+color3)/3;
        //data[i+1]=(color1+color2+color3)/3;
        //data[i+2]=(color1+color2+color3)/3;
    }
end = clock();
time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
cout <<"CPU time = "<<time_spent << "s"<<endl;

///////////////////////////////////////////////////////////
	int	 devCnt;

	cudaGetDeviceCount(&devCnt);
	if(devCnt == 0) {
	perror("No CUDA devices available -- exiting.");
	exit(0);
	}

	
   	cudaMalloc((void**)&dArray, sizeof(hArray));
   	cudaMemcpy(dArray, hArray, sizeof(hArray), cudaMemcpyHostToDevice);

	blocks = N / BLOCK_SIZE;
	if(N % BLOCK_SIZE)
	blocks++;
begin = clock();
	pow3<<<blocks, BLOCK_SIZE>>>(dArray);
end = clock();
time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
cout <<"GPU time = "<<time_spent << "s"<<endl;
	cudaThreadSynchronize();
	
	epilogue();
///////////////////////////////////////////////////////////
    ofstream outfile("malpa2.bmp",ofstream::binary);
    for(i = 0; i<54;i++)
    {
        outfile<<info[i];
    }
    for(i = 0; i<size;i++)
    {
		outfile<<data[i];
    }
    outfile.close();

	ofstream outfile2("malpa3.bmp",ofstream::binary);
    for(i = 0; i<54;i++)
    {
        outfile2<<info[i];
    }
    for(i = 0; i<size;i++)
    {
		outfile2<<hArray[i];
    }
    outfile2.close();
    return data;
}

int main(void)
{
	cout<<fixed;
    //printf("unpacked = %ld\n", sizeof(struct unpacked));
    //printf("packed   = %ld\n", sizeof(struct packed));
	unsigned char* cos = readBMP("malpa.bmp");

    return 0;
}
