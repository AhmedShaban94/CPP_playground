#include "searching_algorithms.hpp"

void searching_algorithms::time_comparison(const std::vector<double>& arr, double key)
{
	//sequential search 
	int found;
	auto start = std::chrono::high_resolution_clock::now();
	found = searching_algorithms::sequential_search(arr, key);
	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::micro> elapsed_time = end - start;
	std::cout << "Sequential search took: " << elapsed_time.count() << " us" << "....";
	found ? std::cout << " found\n" : std::cout << " not found\n";

	//binary search with iterative method 
	start = std::chrono::high_resolution_clock::now();
	found = searching_algorithms::binary_search(arr, key, searching_algorithms::binary_search_method::iterative);
	end = std::chrono::high_resolution_clock::now();
	elapsed_time = end - start;
	std::cout << "Binary search (iterative): " << elapsed_time.count() << " us" << "....";
	found ? std::cout << " found\n" : std::cout << " not found\n";


	//binary search with recursive method 
	start = std::chrono::high_resolution_clock::now();
	found = searching_algorithms::binary_search(arr, key, searching_algorithms::binary_search_method::recursive);
	end = std::chrono::high_resolution_clock::now();
	elapsed_time = end - start;
	std::cout << "Binary search (recursive): " << elapsed_time.count() << " us" << "....";
	found ? std::cout << " found\n" : std::cout << " not found\n";
}

std::vector<double> searching_algorithms::slice(const std::vector<double>& v, int m, int n)
{
	auto first = v.cbegin() + m;
	auto last = v.cbegin() + n + 1;
	std::vector<double> vec(first, last);
	return vec;
}


int searching_algorithms::sequential_search(std::vector<double> array, double key)
{
	for (int i = 0; i < array.size(); ++i)
		if (array.at(i) == key)
		{
			//using transpose method
			std::swap(array.at(i), array.at(i - 1));
			return i;
		}
	return 0;
}

int searching_algorithms::binary_search(const std::vector<double>& arr, double key, searching_algorithms::binary_search_method method)
{
	if (arr.size() == 0)
		return 0;

	//for binary search, the array must be sorted 

	//declaring important variables 
	int first_idx = 0;
	int last_idx = arr.size() - 1;
	int mid_idx;
	//bool found = false;

	switch (method)
	{
	case iterative:
	{
		//binary search using iterative method 
		while (first_idx <= last_idx)
		{
			mid_idx = (first_idx + last_idx) / 2;

			if (arr.at(mid_idx) == key)
			{
				return mid_idx;
			}

			if (key > arr.at(mid_idx))
			{
				first_idx = mid_idx + 1;
			}

			else
			{
				last_idx = mid_idx - 1;
			}
		}
		return 0;
	}

	break;
	case recursive:
	{
		//declaring important variables 
		//std::sort(arr.begin(), arr.end());
		int first_idx = 0;
		int last_idx = arr.size() - 1;

		if (first_idx <= last_idx)
		{
			int mid_idx = arr.size() / 2;
			if (key == arr.at(mid_idx))
			{
				return 1;
			}

			if (arr.at(mid_idx) > key)
			{
				last_idx = mid_idx - 1;
				std::vector<double> sub_vec = slice(arr, first_idx, last_idx);
				return binary_search(sub_vec, key, method);
			}

			else
			{
				first_idx = mid_idx + 1;
				std::vector<double> sub_vec = slice(arr, first_idx, last_idx);
				return binary_search(sub_vec, key, method);
			}
		}
		return 0;
	}
	break;
	}
}