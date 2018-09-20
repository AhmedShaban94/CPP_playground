#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "searching_algorithms.hpp"
#include "sorting_algorithms.hpp" 

int main()
{
	std::vector<int> vec(10);
	std::generate(vec.begin(), vec.end(), std::rand);
	std::vector<int> extreme{ 10,9,8,7,6,5,4,3,2,1,0 };
	sorting_algorithms algorithm(vec, sorting_algorithm_method::selection);
	auto sorted_vector = algorithm.sort();
	for (const auto& ele : sorted_vector)
		std::cout << ele << ' ';
	std::cout << '\n';
	return EXIT_SUCCESS;
}