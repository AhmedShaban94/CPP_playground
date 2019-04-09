#include <iostream>
#include <stdio.h>
#include <cuda.h>
#include <string>
#include "cuda_runtime.h"
#include "device_launch_parameters.h" 
#include <stdlib.h>
#include <ctime> 
#include <math.h>

float* add_cpu(int count, float* arrayA, float* arrayB)
{
	float* arrayC; 
	cudaMallocManaged(&arrayC, sizeof(float)*count); 
	for (int i = 0; i < count; i++)
	{
		arrayC[i] = arrayA[i] + arrayB[i]; 
	}
	return arrayC; 
}

__global__ void add_gpu(int count, float* arrayA, float* arrayB)
{ 
	int index = blockIdx.x * blockDim.x + threadIdx.x; 
	int stride = gridDim.x * blockDim.x; 
	//this called grid-stride loop in cuda. WHY we use this shit ? 
	for (int i = index; i < count; i += stride)
		arrayB[i] = arrayA[i] + arrayB[i];
}
int main()
{
	//one million elements 
	int N = 1<<20; 

	//cuda unified memory allocation 
	float* x; 
	float* y;  
	cudaMallocManaged(&x, sizeof(float)*N); 
	cudaMallocManaged(&y, sizeof(float)*N); 


	//initlization of arrays 
	for (int i = 0; i < N; i++)
	{
		x[i] = 1.0f; 
		y[i] = 2.0f; 
	}

	//run kernel on N elements on CPU
	//float* z = add_cpu(N, x, y); 

	//run kernel on N elements on GPU 
	int blockSize = 256; 
	int numBlock = (N + blockSize - 1) / blockSize; 
	add_gpu <<<numBlock, blockSize>>>(N, x, y); 
	
	//Force CPU to wait until the kernel is done, befor accessing the results for error checking step 
	cudaDeviceSynchronize(); 

	//checking error 
	float maxError = 0.0f; 
	for (int i = 0; i < N; i++)
	{
		maxError = fmax(maxError, fabs(y[i] - 3.0f)); //z[i] for cpu code 
	}
	std::cout << "Max Error = " << maxError << std::endl; 

	cudaFree(x); 
	cudaFree(y);
	//delete[] z; 


	return EXIT_SUCCESS; 
}

