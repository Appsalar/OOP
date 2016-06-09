#include <iostream>
#include "LinkedList.h"

int main()
{

	LinkedList<int> a;
	a.insertAt(420, 3);
	a.insertAt(322, 0);

	a.insertAt(42, 2);
	a.insertAt(1337, 222);

	a.insertAt(20, 2);

	a.setAt(10, 2);

	a.removeAt(4);

	a.clear();

	return 0;
}