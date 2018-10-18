#pragma once 

#include<vector> 
#include <algorithm>
enum sorting_algorithm_method { bubble, quick, insertion, selection, mergeSort, heap };
class sorting_algorithms
{
private:
	//private members. 
	std::vector<int> _arr;
	sorting_algorithm_method _method;

	//Merge sort functions. 
	std::vector<int> merge_sort(std::vector<int> vec);
	std::vector<int> merge(std::vector<int> left, std::vector<int> right);

	//Quick sort functions. 
	void quick_sort(std::vector<int>& vec, int first_index, int last_index);
	int partition(std::vector<int>& vec, int first_index, int last_index);
public:
	/**
	 * \brief
	 * \param arr
	 * \param method
	 */
	sorting_algorithms(std::vector<int> arr, sorting_algorithm_method method);
	~sorting_algorithms();
	std::vector<int> sort();
	bool check(const std::vector<int>& vec, const std::vector<int>& my_sorted) const; 
};