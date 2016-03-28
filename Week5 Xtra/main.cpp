#include <iostream>

int capacity = 0;
int size;


int*  makeBigger(int* arr, int dataToWrite)
{
	if (!arr)
	{
		size = 10;
		arr = new int[size];
	}
	else if (capacity == size)
	{

		int * temp = new int[2 * size];

		size *= 2;

		for (int i = 0;i < capacity;++i)
		{
			temp[i] = arr[i];
		}

		delete[] arr;
		arr = temp;
		temp = NULL;
	}

	arr[capacity] = dataToWrite;
	capacity++;

	return arr;
}



int main()
{

	int * arr;




	size = size;
	arr = new int[size];

	for (int i = 0;i < 42;++i)
	{
		arr[i] = rand() % 43;
		++capacity;
	}


	arr = makeBigger(arr, 420);

	/*if (capacity == size)
	{
	
		int * temp = new int[2 * size];

		for (int i = 0;i < 42;++i)
		{
			temp[i]= arr[i] ;
		}
		delete[]arr;
		arr = temp;
		temp = NULL;
	}

	arr[capacity] = 420;
	capacity++;*/




	return 0;
}