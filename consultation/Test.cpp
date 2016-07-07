#include "Test.h"
#include <iostream>


Test::Test()
{
	arr = NULL;
	size = 0;
	capacity = 0;
}


Test::~Test()
{
	delete[] arr;
}

void Test::addQuestion(Question *elem)
{
	if (capacity == 0)
		resize(2);
	else if (size == capacity)
		resize(2 * capacity);

	arr[size] = elem;
	++size;
}

void Test::doTest()
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i]->ask();
	}
}

double Test::gradeTest() const
{
	double sum = 0;
	for (size_t i = 0; i < size; i++)
	{
		sum += arr[i]->grade();
	}
	return sum;
}

void Test::resize(size_t newSize)
{
	Question** foo = new Question*[newSize];

	for (int i = 0;i < size;++i)
		foo[i] = arr[i];

	delete[] arr;
	arr = foo;
	foo = NULL;
	capacity = newSize;
}
