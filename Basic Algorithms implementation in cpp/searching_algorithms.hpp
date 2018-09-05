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
	int sequential_search(std::vector<double>& array, double key);
	int binary_search(std::vector<double>& array, double key, searching_algorithms::binary_search_method search);
	std::vector<double> slice(std::vector<double>& v, int m, int n);
	void time_comparison(std::vector<double>& arr, double key);
};