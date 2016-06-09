#pragma once

template <class T>
struct Node
{
	T data;
	Node<T>* next;
};


template <class T>
class LinkedList
{
private:
	Node<T>* start;
	Node<T>* last;
	size_t size;

public:
	LinkedList()
	{
		start = nullptr;
		last = nullptr;
		size = 0;
	}

	~LinkedList()
	{
		del();
	}

	void insertAt(const T& newData, size_t index)
	{
		Node<T>* tmp = new Node<T>;
		tmp->data = newData;
		if (size == 0)
		{
			start = tmp;
			last = start;
			tmp->next = nullptr;
		}
		else if (index == 0)
		{
			tmp->next = start;
			start = tmp;
		}
		else if (index >= size)
		{
			last->next = tmp;
			last = tmp;
			last->next = nullptr;
		}
		else
		{
			Node<T>* p = start;
			for (size_t i = 0; i < index - 1; ++i)
				p = p->next;

			tmp->next = p->next;
			p->next = tmp;
		}
		++size;
	}

	void push_back(const T& newData)
	{
		//insertAt(newData, size);
		Node<T>* tmp = new Node<T>;
		tmp->data = newData;

		last->next = tmp;
		last = tmp;
		last->next = nullptr;

		++size;
	}

	void push_front(const T& newData)
	{
		insertAt(newData, 0);
	}

	const T& getAt(size_t index) const
	{
		Node<T>* tmp = start;
		if (index >= size)
			throw std::out_of_range("Wrong index");

		if (index == size - 1)
			return last->data;
		for (size_t i = 0; i < index; i++)
			tmp = tmp->next;

		return tmp->data;
	}

	void setAt(const T& newData, size_t index) const
	{
		Node<T>* tmp = start;
		if (index >= size)
			throw std::out_of_range("Wrong index");

		if (index == size - 1)
		{
			last->data = newData;
			return;
		}

		for (size_t i = 0; i < index; i++)
			tmp = tmp->next;

		tmp->data = newData;
	}

	void removeAt(size_t index)
	{
		Node<T>* tmp = start;
		if (index >= size)
			throw std::out_of_range("Wrong index");

		if (index == 0)
		{
			start = start->next;
			delete tmp;
		}
		else 
		{
			for (size_t i = 0; i < index - 1; i++)
				tmp = tmp->next;

			Node<T>* toDelete = tmp;
			toDelete = toDelete->next;
			tmp->next = toDelete->next;
			delete toDelete;

			if (index == size - 1)
				last = tmp;
		}
		--size;
	}

	void clear()
	{
		del();
	}

	bool empty() const
	{
		return !size;
	}

private:
	void del()
	{
		Node<T>* p = start;
		while (p->next)
		{
			Node<T>* toDel = p;
			p = p->next;
			delete toDel;
		}
		delete p;

		start = last = nullptr;
		size = 0;
	}
};