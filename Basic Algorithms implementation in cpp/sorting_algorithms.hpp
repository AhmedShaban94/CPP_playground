#pragma once 

#include<vector> 

enum sorting_algorithm_method {bubble, quick, insertion, seelction, shell ,merge, heap}; 

template<typename T>
static std::vector<T> sort(std::vector<T> const& vec, sorting_algorithm_method method); 

