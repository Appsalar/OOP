#include <iostream>
#include "YNQuestion.h"
#include "Test.h"
#include "OpenQuestion.h"

using namespace std;


int main()
{
	Test foo;

	YNQuestion a("nigga", 23, false);

	foo.addQuestion(&a);

	OpenQuestion bar("rekt", 12.9);
	foo.addQuestion(&bar);
	foo.doTest();
	cout << foo.gradeTest() << endl;
	return 0;
}