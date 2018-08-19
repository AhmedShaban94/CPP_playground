#pragma once 

#include <vector>
#include <memory>
#include <algorithm>
#include <chrono>
#include <iostream>

class searching_algorithms
{
public:
	//returns index of the key, if exists 
	enum binary_search_method { iterative, recursive };

	static double sequential_search(std::vector<double>& array, int key);

	static double binary_search(std::vector<double>& array, int key, searching_algorithms::binary_search_method search);

	static std::vector<double> slice(std::vector<double>& v, int m, int n);

	static void time_comparison(std::vector<double>& arr, int key);
};