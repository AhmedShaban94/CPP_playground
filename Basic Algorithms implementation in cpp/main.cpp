#include <iostream>
#include <random>
#include "searching_algorithms.hpp"
#include "sorting_algorithms.hpp" 

int main()
{
	searching_algorithms::binary_search_method method = searching_algorithms::binary_search_method::iterative;
	double key;
	std::vector<double> vec(10);
	std::cout << "Enter a number you're searching for\n";
	std::cin >> key;
	vec.push_back(key); 
	std::default_random_engine generator; 
	std::uniform_real_distribution<double> distribution(1,100);  
	for (auto it = vec.begin() + 1; it != vec.end(); ++it)
	{
		*it = distribution(generator); 
	}
	std::cout << "index of " << key << " is " << searching_algorithms::binary_search(vec, key, method) << '\n';
	return EXIT_SUCCESS;
}