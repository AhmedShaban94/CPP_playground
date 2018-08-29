#include <iostream>
#include <random>
#include <ctime>
#include <cstdlib>
#include "searching_algorithms.hpp"
#include "sorting_algorithms.hpp" 

int main()
{
	//driver for testing searching algorithms. 
	std::vector<double> vec{ 10, 5, 6, 8, 9, 5, 6, 1, 2, 22, 45, 7, 10 }; 
	searching_algorithms algorithm; 
	double key; 
	std::cout << "Enter key: \n"; 
	std::cin >> key; 
	algorithm.time_comparison(vec, key); 
	return EXIT_SUCCESS;
}