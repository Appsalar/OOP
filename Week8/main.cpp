#include <iostream>
#include "Array.h"

int main()
{
	Array a;

	a.push_back(10);
	a.push_back(20);
	a.push_back(42);

	a.setAt(1, 322);
	a.pop(10);
	a.pop(322);
	a.pop(42);
	return 0;
}