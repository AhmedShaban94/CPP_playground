#include <iostream>
#include "searching_algorithms.hpp"
#include "sorting_algorithms.hpp" 

int main()
{
	int key;
	std::cin >> key;
	std::vector<int> vec{ 1,2,3,4,5 };
	std::cout << "index of " << key << " : " << searching_algorithms::sequential_search(vec, key);
	return EXIT_SUCCESS;
}