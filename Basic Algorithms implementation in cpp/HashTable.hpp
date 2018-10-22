#pragma once 
#include "HashNode.hpp"
#include <vector>


class HashTable
{
private:
	int m_table_size;
	std::vector<std::vector<HashNode>> table;
public:

	HashTable(int table_size)
	{
		m_table_size = table_size;
		table.resize(m_table_size, std::vector<HashNode>());
	}

	~HashTable()
	{
		table.clear();
	}

	double get(int key) const
	{
		auto hash = key % m_table_size;
		if (table[hash].empty())
			return -1;
		for (const auto& element : table[hash])
			if (element.getKey() == key)
				return element.getValue();
		return -1;
	}

	void put(int key, double value)
	{
		HashNode node(key, value);
		auto hash = key % m_table_size;
		table[hash].push_back(node);
		table[hash].shrink_to_fit();
	}

	void remove(int key)
	{
		auto hash = key % m_table_size;
		unsigned int index = 0;
		for (index = 0; index < table[hash].size(); ++index)
			if (table[hash][index].getKey() == key)
				break;
		table[hash].erase(table[hash].begin() + index);
		table[hash].shrink_to_fit();
	}

	void show() const
	{
		for (const auto& sub_vector : table)
			if (sub_vector.empty())
				continue;
			else
				for (const auto& node : sub_vector)
					std::cout << "Key: " << node.getKey() << " Value: " << node.getValue() << '\n';
	}
};
