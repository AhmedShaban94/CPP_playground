#pragma once 

template <typename K, size_t table_size>
class KeyHash
{
public:
	unsigned long operator() (const K &key) const
	{
		return reinterpret_cast<unsigned long> key % table_size;
	}
};