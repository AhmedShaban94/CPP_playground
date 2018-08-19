#include "searching_algorithms.hpp"

void searching_algorithms::time_comparison(std::vector<double>& arr, int key)
{
	//sequential search 
	auto start = std::chrono::system_clock::now();
	searching_algorithms::sequential_search(arr, key);
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double, std::milli> elapsed_time = end - start;
	std::cout << "Sequential search took: " << elapsed_time.count() << " ms" << '\n';

	//binary search with iterative method 
	start = std::chrono::system_clock::now();
	searching_algorithms::binary_search(arr, key, searching_algorithms::binary_search_method::iterative);
	end = std::chrono::system_clock::now();
	elapsed_time = end - start;
	std::cout << "Binary search (iterative): " << elapsed_time.count() << " ms" << '\n';

	//binary search with recursive method 
	start = std::chrono::system_clock::now();
	searching_algorithms::binary_search(arr, key, searching_algorithms::binary_search_method::recursive);
	end = std::chrono::system_clock::now();
	elapsed_time = end - start;
	std::cout << "Binary search (recursive): " << elapsed_time.count() << " ms" << '\n';
}

std::vector<double> searching_algorithms::slice(std::vector<double>& v, int m, int n)
{
	auto first = v.cbegin() + m;
	auto last = v.cbegin() + n + 1;
	std::vector<double> vec(first, last);
	return vec;
}


double searching_algorithms::sequential_search(std::vector<double>& array, int key)
{
	for (int i = 0; i < array.size(); ++i)
		if (array.at(i) == key)
		{
			//using transpose method
			std::swap(array.at(i), array.at(i - 1));
			return (i);
		}
	return 0;
}

double searching_algorithms::binary_search(std::vector<double>& arr, int key, searching_algorithms::binary_search_method method)
{
	if (arr.size() == 0)
		return 0;

	//the array must be sorted to perform binary search  
	std::sort(arr.begin(), arr.end());

	//declaring important variables 
	int first_idx = 0;
	int last_idx = arr.size() - 1;
	int mid_idx;
	bool found = false;

	switch (method)
	{
	case iterative:
	{
		//binary search using looping method 
		while (first_idx <= last_idx && !found)
		{
			mid_idx = (first_idx + last_idx) / 2;

			if (arr.at(mid_idx) == key)
			{
				found = true;
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
	}

	case recursive:
	{
		mid_idx = arr.size() / 2;
		if (key == arr.at(mid_idx))
			return mid_idx;

		if (key > arr.at(mid_idx))
		{
			first_idx = mid_idx + 1;
			std::vector<double> sub_vec = slice(arr, first_idx, last_idx);
			binary_search(sub_vec, key, method);
		}

		else
		{
			last_idx = mid_idx - 1;
			std::vector<double> sub_vec = slice(arr, first_idx, last_idx);
			binary_search(sub_vec, key, method);
		}

	}

	}
}