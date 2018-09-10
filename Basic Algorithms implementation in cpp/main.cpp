#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "searching_algorithms.hpp"
#include "sorting_algorithms.hpp" 

int main()
{
	//driver for testing searching algorithms. 
	searching_algorithms algorithm;
	std::vector<double> vec(1000);
	std::generate(vec.begin(), vec.end(), std::rand);
	double key = *(vec.cend() - 1);
	algorithm.time_comparison(vec, key);
	return EXIT_SUCCESS;
}