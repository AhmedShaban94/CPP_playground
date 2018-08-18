#include "searching_algorithms.hpp"

//template <class T>
int searching_algorithms::sequential_search(std::vector<double>& array, int key)
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

//template <class T>
int searching_algorithms::binary_search(std::vector<double>& arr, int key, searching_algorithms::binary_search_method method)
{
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

	}

	}

}
