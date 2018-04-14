#pragma once
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

void findClosestPoint(float3* points, int* indicies, int count)
{
	//Base case, if there is 1 point don't do anything. 
	if (count <= 1)
		return; 
	//loop through every point 
	for (int currentPoint = 0; currentPoint < count; currentPoint++)
	{
		//this variable is set to nearest point, init it with float.max
		float closestSoFar = 3.40282e38f; 
		for (int i = 0; i < count; i++)
		{
			//don't calculate the distance from the currentPoint to itself.
			if (i == currentPoint)
				continue; 
			//We removed the sqrt function as it will harm the performance. 
			float dist = (points[currentPoint].x - points[i].x) * (points[currentPoint].x - points[i].x); 
			dist += (points[currentPoint].y - points[i].y) * (points[currentPoint].y - points[i].y);
			dist += (points[currentPoint].z - points[i].z) * (points[currentPoint].z - points[i].z);
			if (dist < closestSoFar)
			{
				closestSoFar = dist; 
				indicies[currentPoint] = i; 
			}
		}
	}
}