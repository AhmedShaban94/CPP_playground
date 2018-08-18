#include <iostream>
#include "searching_algorithms.hpp"
#include "sorting_algorithms.hpp" 

int main()
{
	searching_algorithms::binary_search_method method = searching_algorithms::binary_search_method::iterative;
	int key;
	std::cout << "Enter a number you're searching for\n";
	std::cin >> key;
	std::vector<int> vec{ 1,2,3,4,5 };
	std::cout << "index of " << key << " is " << searching_algorithms::binary_search(vec, key, method) << '\n';
	return EXIT_SUCCESS;
}