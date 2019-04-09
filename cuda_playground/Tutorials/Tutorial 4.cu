#include <iostream>
#include <stdio.h>
#include <cuda.h>
#include <string>
#include "cuda_runtime.h"
#include "device_launch_parameters.h" 
#include <stdlib.h> 
#include <assert.h>
/*Tutorial 4 from cuda articels series about suing pinned memory directly without using pageable memory.*/
//Note: Don't over_use pinned memory and use it in narrowest limits. 

inline
cudaError_t cudaCheck(cudaError_t result)
{
#if defined(DEBUG) || defined(_DEBUG)
	{
		if (result != cudaSuccess)
		{
			fprintf(stderr, "Cuda runtime error", cudaGetErrorString(result));
			assert(cudaSuccess == result);
		}
	}
#endif 
	return result;
}

void profileCopies(float *h_a, float *h_b, float *d, unsigned int n, const char *desc)
{
	printf("\n%s transfer \n", desc);
	unsigned int bytes = n * sizeof(float);

	//cuda events for timing
	cudaEvent_t start, end;
	cudaCheck(cudaEventCreate(&start));
	cudaCheck(cudaEventCreate(&end));

	cudaCheck(cudaEventRecord(start, 0));
	cudaCheck(cudaMemcpy(d, h_a, bytes, cudaMemcpyHostToDevice));
	cudaCheck(cudaEventRecord(end, 0));
	cudaCheck(cudaEventSynchronize(end));

	float time;
	cudaCheck(cudaEventElapsedTime(&time, start, end));
	printf("Host to Device Bandwidth (Gb/s): %f\n", bytes * 1e-6 / time);

	cudaCheck(cudaEventRecord(start, 0));
	cudaCheck(cudaMemcpy(h_b, d, bytes, cudaMemcpyDeviceToHost));
	cudaCheck(cudaEventRecord(end, 0));
	cudaCheck(cudaEventSynchronize(end));

	cudaCheck(cudaEventElapsedTime(&time, start, end));
	printf("Device to Host Bandwidth (Gb/s): %f\n", bytes * 1e-6 / time);

	//checking transfer 
	for (int i = 0; i < n; i++)
	{
		if (h_a[i] != h_b[i])
		{
			printf("%s transfer failed\n");
			break;
		}
	}
	cudaCheck(cudaEventDestroy(start));
	cudaCheck(cudaEventDestroy(end));
}

int main()
{
	//number of elements in each array 
	unsigned int numElements = 1024 * 1024 * 4;
	const unsigned int bytes = numElements * sizeof(float);

	//host arrays 
	float *h_aPageable, *h_bPageable;
	float *h_aPinned, *h_bPinned;

	//device array 
	float *d;

	//allocate memory on host and device 
	h_aPageable = new float[bytes];
	h_bPageable = new float[bytes];
	cudaCheck(cudaMallocHost(&h_aPinned, bytes));
	cudaCheck(cudaMallocHost(&h_bPinned, bytes));
	cudaCheck(cudaMalloc(&d, bytes));

	//initilize memory arrays  
	for (int i = 0; i < numElements; i++) h_aPageable[i] = i;
	memcpy(h_aPageable, h_aPageable, bytes);
	memset(h_bPageable, 0, bytes);
	memcpy(h_bPinned, h_bPageable, bytes);

	//getting device properties 
	cudaDeviceProp prop;
	cudaGetDeviceProperties(&prop, 0); 
	printf("\nDevice Name \"%s\"\n", prop.name);
	printf("\nTransfer size (MB): %d\n", bytes / (1024 * 1024));

	//performing data_transfer to compare speed between paegable and pinned memory 
	profileCopies(h_aPageable, h_bPageable, d, numElements, "Pageable"); 
	profileCopies(h_aPinned, h_bPinned, d, numElements, "Pinned"); 

	//clean up memory 
	delete[] h_aPageable; 
	delete[] h_bPageable; 
	cudaFreeHost(h_aPinned); 
	cudaFreeHost(h_bPinned); 
	cudaFree(d); 

	return EXIT_SUCCESS; 
}