#include "searching_algorithms.hpp"

int searching_algorithms::sequential_search(std::vector<int>& array, int key)
{
	for (int i = 0; i < array.size(); ++i)
		if (array.at(i) == key)
		{
			//using transpose method
			std::swap(array.at(i), array.at(i - 1)); 
			return (i - 1);
		}
	return 0;
}
