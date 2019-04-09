#include <iostream>
#include <cuda.h>
#include <string>
#include "cuda_runtime.h"
#include "device_launch_parameters.h" 
#include <stdlib.h>
#include <ctime> 

#include"FindClosestCPU.h"

using std::cout;

__global__ void findClosestGPU(float3* points, int* indicies, int count)
{
	if (count <= 1)
		return;

	int idx = threadIdx.x + blockIdx.x * blockDim.x;
	if (idx < count)
	{
		float3 thisPoint = points[idx];
		float closestSoFar = 3.40282e38f;

		for (int i = 0; i < count; i++)
		{
			if (idx == i)
				continue;
			float dist = (thisPoint.x - points[i].x) * (thisPoint.x - points[i].x);
			dist += (thisPoint.y - points[i].y) * (thisPoint.y - points[i].y);
			dist += (thisPoint.z - points[i].z) * (thisPoint.z - points[i].z);
			if (dist < closestSoFar)
			{
				dist = closestSoFar;
				indicies[idx] = i;
			}
		}
	}
}

int main()
{
	float3* d_points; 
	int* d_indexOfClosest; 
	cudaMalloc(&d_points, sizeof(float3)); 
	cudaMalloc(&d_indexOfClosest, sizeof(int)); 
	//number of points 
	const int count = 10000;

	//arrays of points 
	int* indexOfclosest = new int[count]; 
	float3* points = new float3[count]; 

	//create a list of random points 
	for (int i = 0; i < count; i++)
	{
		points[i].x = (float)(rand() % 10000 - 5000); 
		points[i].y = (float)(rand() % 10000 - 5000); 
		points[i].z = (float)(rand() % 10000 - 5000); 
	}

	cudaMemcpy(d_points, points, count, cudaMemcpyHostToDevice); 
    cudaMemcpy(d_indexOfClosest, indexOfclosest, count, cudaMemcpyHostToDevice); 

	//this variable is set to keep track of the fastest time so far 
	long fastestTime = 1000000; 

	//run the algorithm 20 times 
	for (int run = 0; run < 20; run++)
	{
		long startTime = clock(); 
		//findClosestPoint(points, indexOfclosest, count); 
		findClosestGPU << <(count / 32) + 1, 32 >> > (points, indexOfclosest, count); 
		cudaMemcpy(indexOfclosest, d_indexOfClosest, sizeof(int)*count, cudaMemcpyDeviceToHost); 
		cudaMemcpy(points, d_points, sizeof(float3)*count, cudaMemcpyDeviceToHost); 
		long endTime = clock(); 
		cout << "Run no. " << run << " took " << endTime - startTime << " millis\n"; 
		//if the run time was fastest that the fastestTime, Update fastestTime. 
		if ((endTime - startTime) < fastestTime)
		{
			fastestTime = endTime - startTime; 
		}
	}
	//print out fastestTime. 
	cout << "Fastest Time is: " << fastestTime << " millis\n";

	//print the final results to screen 
	cout << "final results\n";
	for (int i = 0; i < 10; i++)
	{
		cout << i << ". " << indexOfclosest[i] << std::endl;
	}
	
	//deallocate CPU ram 
	delete[] indexOfclosest;
	delete[] points;

	//deallocate Cuda memory 
	cudaFree(d_points); 
	cudaFree(d_indexOfClosest); 
	cudaDeviceReset(); 

	return EXIT_SUCCESS; 
}


