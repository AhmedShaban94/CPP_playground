#include <iostream>
#include <stdio.h>
#include <cuda.h>
#include <string>
#include "cuda_runtime.h"
#include "device_launch_parameters.h" 
#include <stdlib.h>
#include <ctime> 
#include <math.h>
//Tutorial 2 "How to Implement Performance Metrics in CUDA C/C++" 
__global__ 
void sexpy(int n,int a, float* x, float* y)
{
	int index = blockDim.x * blockIdx.x + threadIdx.x; 
	int stride = blockDim.x * gridDim.x; 

	for (int i = index; i < n; i += stride)
	{
		y[i] = a*x[i] + y[i]; 
	}
}

int main()
{
	int nElements = 20 * (1 << 20); 

	float *x_h, *y_h, *x_d, *y_d; 
	x_h = new float[nElements]; 
	y_h = new float[nElements]; 

	cudaMalloc(&x_d, sizeof(float)*nElements); 
	cudaMalloc(&y_d, sizeof(float)*nElements); 

	//fill host array 
	for (int i = 0; i < nElements; i++)
	{
		x_h[i] = 1.0f; 
		y_h[i] = 2.0f; 
	}

	cudaEvent_t start, stop; 
	cudaEventCreate(&start); 
	cudaEventCreate(&stop); 

	//copy data from host to device 
	cudaMemcpy(x_d, x_h, nElements * sizeof(float), cudaMemcpyHostToDevice); 
	cudaMemcpy(y_d, y_h, nElements * sizeof(float), cudaMemcpyHostToDevice);

	cudaEventRecord(start);
	sexpy << <(nElements + 511) / 512, 256 >> > (nElements, 2.0f, x_d, y_d); 
	cudaEventSynchronize(stop);  

	float milliseconds = 0; 
	cudaEventElapsedTime(&milliseconds, start, stop); 
	printf("Effective Bandwidth (GB/s): %fn \n", nElements * 4 * 3 / milliseconds / 1e6);
	
	
	cudaMemcpy(y_h, y_d, nElements * sizeof(float), cudaMemcpyDeviceToHost); 
	for (int i = 0; i < nElements; i++)
	{
		std::cout << float(y_h[i]) << std::endl; 
	}

	delete[] x_h; 
	delete[] y_h; 
	cudaFree(x_d); 
	cudaFree(y_d); 

	return EXIT_SUCCESS;
}