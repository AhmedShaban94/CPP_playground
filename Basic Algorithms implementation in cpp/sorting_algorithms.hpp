#pragma once 

#include<vector> 
enum sorting_algorithm_method { bubble, quick, insertion, selection, mergeSort, heap };
class sorting_algorithms
{
private:
	std::vector<int> _arr;
	sorting_algorithm_method _method;
	std::vector<int> merge_sort(std::vector<int> vec);
	std::vector<int> merge(std::vector<int> left, std::vector<int> right);
public:
	sorting_algorithms(std::vector<int> arr, sorting_algorithm_method method);
	~sorting_algorithms();
	std::vector<int> sort();
};

