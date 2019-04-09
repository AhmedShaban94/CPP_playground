#include <iostream>
#include <cuda.h>
#include <string>
#include "cuda_runtime.h"
#include "device_launch_parameters.h" 
#include <stdlib.h>
#include <ctime> 

__global__ void kernel(int* a, int* b, int* c, int count)
{
	int id = blockDim.x * blockIdx.x + threadIdx.x; 
	if (id < count)
	{
		c[id] = a[id] + b[id]; 
	}
}

int main()
{
	srand(time(NULL));
	//init host containers 
	int count = 10;
	int* h_a = new int[count];
	int* h_b = new int[count];
	int* h_c = new int[count]; 

	//init device containers 
	int* d_a;
	int* d_b;
	int* d_c; 

	//filling the host arrays 
	for (int i = 0; i < count; i++)
	{
		h_a[i] = rand() % 1000;
		h_b[i] = rand() % 1000;
	}


	//cuda memory allocation of array (a)
	if (cudaMalloc(&d_a, sizeof(int)*count) != cudaSuccess)
	{
		delete[] h_a; 
		delete[] h_b;
	}

	//cuda memory allocation of array (b) 
	if (cudaMalloc(&d_b, sizeof(int)*count) != cudaSuccess)
	{
		delete[] h_a; 
		delete[] h_b; 
		cudaFree(d_a); 
	}

	//cuda mmeory allocation of array(c) 
	if (cudaMalloc(&d_c, sizeof(int) * count) != cudaSuccess)
	{
		delete[] h_a; 
		delete[] h_b; 
		cudaFree(d_a); 
		cudaFree(d_b); 
 	}
	//cuda memory copy from host to device array (a) 
	if (cudaMemcpy(d_a, h_a, sizeof(int) * count, cudaMemcpyHostToDevice) != cudaSuccess)
	{
		std::cout << "failed to memory copy of array A \n"; 
		delete[] h_a; 
		delete[] h_b;
		cudaFree(&d_a); 
		cudaFree(&d_b); 
	}

	//cuda memory copy from host to device array (b) 
	if (cudaMemcpy(d_b, h_b, sizeof(int) * count, cudaMemcpyHostToDevice) != cudaSuccess)
	{
		std::cout << "failed to memory copy of array B \n";
		delete[] h_a;
		delete[] h_b;
		cudaFree(&d_a);
		cudaFree(&d_b);
	}

	//calling the kernel from host to be executed on device 
	kernel << <count / 256 + 1, 256 >> > (d_a, d_b, d_c, count); 

	//cuda memory copy from device to host of array(a)
	if (cudaMemcpy(h_a, d_a, sizeof(int) * count, cudaMemcpyDeviceToHost) != cudaSuccess)
	{
		delete[] h_a; 
		delete[] h_b; 
		cudaFree(&d_a); 
		cudaFree(&d_b); 
		cudaFree(&d_c); 
	}

	//cuda mmeory copy from device to host of array(b)
	if (cudaMemcpy(h_b, d_b, sizeof(int) * count, cudaMemcpyDeviceToHost) != cudaSuccess)
	{
		delete[] h_a; 
		delete[] h_b; 
		cudaFree(&d_a); 
		cudaFree(&d_b); 
		cudaFree(&d_c); 
	}

	//cuda memory copy form device to host of array(c) 
	if (cudaMemcpy(h_c, d_c, sizeof(int)*count, cudaMemcpyDeviceToHost) != cudaSuccess)
	{
		delete[] h_a; 
		delete[] h_b; 
		delete[] h_c; 
		cudaFree(d_a); 
		cudaFree(d_b); 
		cudaFree(d_c); 
	}

	//showing the filled arrays 
	for (int i = 0; i < count; i++)
	{
		std::cout << h_c[i] << " " << "= " << h_a[i] << " + " << h_b[i] << std::endl;
	} 

	delete[] h_a; 
	delete[] h_b; 
	delete[] h_c; 
	cudaFree(d_a); 
	cudaFree(d_b); 
	cudaFree(d_c); 

	return EXIT_SUCCESS; 
}
