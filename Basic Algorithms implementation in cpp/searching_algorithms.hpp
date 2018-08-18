#include <vector>
#include <memory>
#include <algorithm>

class searching_algorithms
{
public:
	//returns index of the key, if exists 
	enum binary_search_method { iterative, recursive };

	//template <class T> 
	static int sequential_search(std::vector<double>& array, int key);

	//template <class T>
	static int binary_search(std::vector<double>& array, int key, searching_algorithms::binary_search_method search);
};