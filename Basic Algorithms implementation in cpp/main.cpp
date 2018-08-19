#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "searching_algorithms.hpp"
#include "sorting_algorithms.hpp" 


int main()
{
	searching_algorithms::binary_search_method method = searching_algorithms::binary_search_method::iterative;
	double key;
	std::vector<double> vec(10);
	std::cout << "Enter a number you're searching for\n";
	std::cin >> key;
	std::default_random_engine generator;
	std::uniform_real_distribution<double> distribution(1, 100);
	for (auto it = vec.begin() + 1; it != vec.end(); ++it)
	{
		*it = distribution(generator);
	}

	//putting th key in random place in the vector. 
	srand(time(0));
	int random_index = rand() % vec.size(); 
	vec.at(random_index) = 5.0; 
	
	//for noe, can't retrive the index of the key for binary search using recursive method. 
	std::cout << "index of " << key << " is " << searching_algorithms::binary_search(vec, key, method) << '\n';

	searching_algorithms::time_comparison(vec, key); 
	return EXIT_SUCCESS;
}