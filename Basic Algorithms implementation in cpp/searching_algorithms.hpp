#include <vector>
#include <memory>
#include <algorithm>

class searching_algorithms
{
public:
	//returns index of the key, if exists 
	enum binary_search_method { iterative, recursive };
	static int sequential_search(std::vector<int>& array, int key);
	static int binary_search(std::vector<int>& array, int key, searching_algorithms::binary_search_method search);
};