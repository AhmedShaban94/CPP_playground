#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "searching_algorithms.hpp"
#include "sorting_algorithms.hpp" 

int main()
{
	//Sorting algorithms driver.
	std::vector<int> vec(100);
	std::generate(vec.begin(), vec.end(), std::rand);
	sorting_algorithms::time_comparison(vec);
	return EXIT_SUCCESS;
}