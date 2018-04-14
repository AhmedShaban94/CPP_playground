#include <iostream>
#include <stdio.h>
#include <cuda.h>
#include <string>
#include "cuda_runtime.h"
#include "device_launch_parameters.h" 
#include <stdlib.h>
#include <ctime> 
#include <math.h>
//Tutorial 3 "How to Query device properties and handle errors in CUDA C/C++" 

__global__
void saxpy(int n, float a, float* x, float* y)
{
	int index = blockDim.x * blockIdx.x + threadIdx.x;
	int stride = gridDim.x * blockDim.x;
	for (int i = index; i < n; i += stride)
	{
		y[i] = a*x[i] + y[i];
	}
}
int main()
{
	//Querying devices properties 
	int nDevices = 0;
	cudaError_t error = cudaGetDeviceCount(&nDevices);
	if (error != cudaSuccess) printf("%s", cudaGetErrorString(error));
	printf("Number of devices = %d\n", nDevices);
	for (int i = 0; i < nDevices; i++)
	{
		cudaDeviceProp prop;
		cudaGetDeviceProperties(&prop, i);
		printf("Properties of Device number %d :\n", i);
		printf("Device %d name is %s \n", i, prop.name);
		printf("Device %d clock rate = %d KHz\n", i, prop.clockRate);
		printf("Device %d compute capability is %d.%d \n", i, prop.major, prop.minor);
		printf("Device %d memory clockRate = %d KHz\n", i, prop.memoryClockRate);
		printf("Devide %d maximum grid size = %d grid\n", i, prop.maxGridSize);
		printf("Device %d memory bus width = %d bits\n", i, prop.memoryBusWidth);
		printf("Device %d Peak mmeory bandwidth = %f  (GB/s)\n", i, 2.0*prop.memoryClockRate*(prop.memoryBusWidth / 8) / 1.0e6);

		//code can be extended further to print all fields in cudaDeviceProp struct
		//but deviceQuery in CUDA samples already do this.
		//this code just for demonstration 
	}

	//Handling errors
	int n = 1 << 20;
	float *h_x, *h_y, *d_x, *d_y;
	h_x = new float[n];
	h_y = new float[n];
	cudaMalloc(&d_x, n * sizeof(float));
	cudaMalloc(&d_y, n * sizeof(float));

	for (int i = 0; i < n; i++)
	{
		h_x[i] = 1.0f;
		h_y[i] = 2.0f;
	}

	cudaMemcpy(d_x, h_x, n * sizeof(float), cudaMemcpyHostToDevice);
	cudaMemcpy(d_y, h_y, n * sizeof(float), cudaMemcpyHostToDevice);

	saxpy << <(n + 255) / 256, 256 >> > (n, 2.0f, d_x, d_y);

	//Invalid execution configuration parameters, e.g.too many threads per thread block
	//, are reflected in the value of errSync returned by cudaGetLastError()
	cudaError_t errorSync = cudaGetLastError();

	//Asynchronous errors which occur on the device after control is returned to the host,
	//such as out - of - bounds memory accesses, require a synchronization mechanism such as cudaDeviceSynchronize()
	//Device Synch is expensiv, so use it with care. Use it in debug mode but avoid it in release mode.
	cudaError_t errorAsync = cudaDeviceSynchronize();
	if (errorAsync != cudaSuccess) printf("%s", cudaGetErrorString(errorAsync));
	if (errorSync != cudaSuccess) printf("%s", cudaGetErrorString(errorSync));

	cudaMemcpy(h_y, d_y, n * sizeof(float), cudaMemcpyDeviceToHost);

	for (int i = 0; i < n; i++)
	{
		printf("%.1f\n", h_y[i]);
	}

	delete[] h_x;
	delete[] h_y;
	cudaFree(d_x);
	cudaFree(d_y);

	return EXIT_SUCCESS;
}