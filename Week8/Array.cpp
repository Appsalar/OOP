#include "Array.h"
#include <iostream>
#include <stdexcept>


Array::Array()
{
	pArr = NULL;
	size = 0;
	capacity = 0;
}

Array::Array(const Array& other)
{
	pArr = NULL;
	copyElements(other);
}

Array& Array::operator=(const Array& other)
{
	if (this != &other)
		copyElements(other);
	return *this;
}

Array::~Array()
{
	delete[] pArr;
}


int Array::getSize() const
{
	return size;
}


void Array::push_back(int elem)
{
	if (capacity == 0)
		setSize(2);
	else if (size == capacity)
		setSize(2 * capacity);

	pArr[size] = elem;
	++size;
}


void Array::pop(int key)
{
	if (size == 0)
		return;

	for (int i = 0;i < size;++i)
	{
		if (pArr[i] == key)
		{
			for (int j = i;j < size;++j)
				pArr[j] = pArr[j + 1];
			--size;
		}
	}

	if (size == 0)
	{
		delete[] pArr;
		pArr = NULL;
		capacity = 0;
	}
	else if (size <= capacity / 4)
		setSize(capacity / 2);
}


int Array::getAt(int index) const
{
	if (index < 0 || index >= size)
		throw std::out_of_range("360 NO SKOPE");
	return pArr[index];
}


void Array::setAt(int index, int newElem)
{
	if (index < 0 || index >= size)
		throw std::out_of_range("360 NO SKOPE");
	pArr[index]  = newElem;
}


void Array::copyElements(const Array& other)
{
	size = other.size;
	setSize(other.capacity);
	for (int i = 0;i < size;++i)
		pArr[i] = other.pArr[i];
}


void Array::setSize(int newSize)
{
	int* foo = new int[newSize];

	for (int i = 0;i < size;++i)
		foo[i] = pArr[i];

	delete[] pArr;
	pArr = foo;
	foo = NULL;
	capacity = newSize;
}
