#pragma once 

#include<vector> 
enum sorting_algorithm_method { bubble, quick, insertion, selection, merge, heap };
class sorting_algorithms
{
private:
	std::vector<int> _arr;
	sorting_algorithm_method _method;
public:
	sorting_algorithms(std::vector<int> arr, sorting_algorithm_method method);
	~sorting_algorithms();
	std::vector<int> sort();
};

