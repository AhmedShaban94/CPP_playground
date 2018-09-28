#include <iostream>
#include "sorting_algorithms.hpp"

sorting_algorithms::sorting_algorithms(std::vector<int> arr, sorting_algorithm_method method)
	: _arr{ arr }, _method{ method } {}

sorting_algorithms::~sorting_algorithms() { _arr.clear(); }

std::vector<int> sorting_algorithms::sort()
{
	std::vector<int> vec;
	switch (_method)
	{
	case bubble:
	{
		std::cout << "performing bubble sort\n";
		vec = _arr;
		bool sorted = false;
		int pass_through = vec.size() - 1;
		while (!sorted)
		{
			sorted = true;
			//for loop for passes through.
			for (int i = 0; i < pass_through; ++i)
				//for loop to swap adjasent elements except the sorted ones (i). 
				for (int j = 0; j < pass_through - i; ++j)
					if (vec[j] > vec[j + 1])
					{
						sorted = false;
						std::swap(vec[j], vec[j + 1]);
					}
		}
		break;
	}
	case selection:
	{
		std::cout << "performing selection sort\n";
		vec = _arr;
		int n = vec.size();
		int i, j, min_index;
		//looping on all elements up to the last elemnt/index. 
		for (i = 0; i < n - 1; ++i)
		{
			min_index = i;
			//looping on all elements 
			for (j = i + 1; j < n; ++j)
			{
				if (vec[min_index] > vec[j])
					min_index = j;
			}
			std::swap(vec[min_index], vec[i]);
		}
		break;
	}
	case insertion:
	{
		std::cout << "performing insertion sort\n";
		vec = _arr;
		int i, hole_index, temp, size = vec.size(); //hole_idex is (j) in my mind :D 

		// perform outer loop
		for (i = 0; i < size - 1; ++i)
		{
			hole_index = i + 1;
			temp = vec[hole_index];
			// perform shifting loop
			while (hole_index > 0 && temp < vec[hole_index - 1])
			{
				vec[hole_index] = vec[hole_index - 1];
				--hole_index;
			}
			// assigning temp value to the right position
			vec[hole_index] = temp;
		}
		break;
	}
	case merge:
	{
		std::cout << "performing merge sort\n";
		break;
	}
	case quick:
	{
		std::cout << "performing quick sort\n";
		break;
	}
	case heap:
	{
		std::cout << "performing heap sort\n";
		break;
	}
	default:
	{
		std::cout << "no sorting algorithm selected\n";
		break;
	}
	}
	return vec;
}
