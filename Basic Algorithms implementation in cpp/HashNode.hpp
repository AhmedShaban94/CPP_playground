#pragma once 
#include <memory>
#include <iostream>
class HashNode
{
private:

	int m_key;
	double m_value;

public:
	
	HashNode(int key, double value) : m_key(key), m_value(value) {};
	
	HashNode()
	{
		m_value = NULL;
	}

	~HashNode() = default;

	int getKey() const
	{
		return m_key;
	}

	double getValue() const
	{
		return m_value;
	}

	void setValue(double value)
	{
		m_value = value;
	}
};