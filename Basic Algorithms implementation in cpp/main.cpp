#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "searching_algorithms.hpp"
#include "sorting_algorithms.hpp" 
#include "HashTable.hpp"

int main()
{
	//Sorting algorithms driver.
	std::vector<int> vec(100);
	std::generate(vec.begin(), vec.end(), std::rand);
	sorting_algorithms::time_comparison(vec);
	std::cout << '\n'; 

	//Hash table driver. 
	auto table = std::make_unique<HashTable>(10);
	table->put(5, 10);
	table->put(1, 2);
	table->put(3, 5);
	table->remove(5); 
	std::cout << table->get(5) << '\n';
	return EXIT_SUCCESS;
}

