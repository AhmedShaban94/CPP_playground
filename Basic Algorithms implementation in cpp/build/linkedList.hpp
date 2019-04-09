#pragma once
#include <memory>
#include <iostream>

template <typename T>
class linkedList
{

protected:
	class Node
	{
	private:
		int index;
		T data;
		Node* next;
	public:
		Node() : index(globalIndex++), next(nullptr) {}
		T getData();
		void setData(T data);
		Node* getNext();
		void setNext(Node* next);
	};

private:
	Node* head;
	static int globalIndex;
public:
	linkedList() : head(new Node()) {}
	virtual ~linkedList();
	std::pair<bool, int> search(T data);
	void insertNode(const int index);
	void deleteNode(const int index);
	void insertAtLast();
	void deleteAtLast();
	friend std::ostream& operator << (std::ostream& out, const linkedList& list);
};

template<typename T>
int linkedList<T>::globalIndex = 0;

template <typename T>
linkedList<T>::~linkedList()
{
	std::unique_ptr<node> current = this->head;
	while (current->getNext() != nullptr)
	{
		auto temp = current->getNext();
		linkedList::deleteNode(current);
		current = temp;
	}
}

template <typename T>
std::pair<bool, int> linkedList<T>::search(T data)
{
	auto current = head;
	while (current != nullptr)
	{
		if (current->getData() == data)
			return std::make_pair(true, current->index);
		else
			current = current->getNext();
	}
	return std::make_pair(false, NULL);
}

template <typename T>
void linkedList<T>::insertNode(const int index)
{

}

template <typename T>
void linkedList<T>::insertAtLast()
{
	auto current = head;
	while (current->getNext() != nullptr)
	{
		current = current->getNext();
	}
	auto newNode = new Node();
	newNode->index = ++globalIndex;
	current->setNext(new Node());
}

template<typename T>
void linkedList<T>::deleteAtLast()
{
}

template <typename T>
T linkedList<T>::Node::getData()
{
	return  this->data;
}

template<typename T>
void linkedList<T>::Node::setData(T data)
{
	this->data = data;
}

template <typename T>
typename linkedList<T>::Node* linkedList<T>::Node::getNext()
{
	return this->next;
}

template <typename T>
void linkedList<T>::Node::setNext(Node* next)
{
	this->next = next;
}
