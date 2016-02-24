#include <iostream>
#include "Functions.h"
#include "Functions.h"
#include <stdlib.h>
#include <Windows.h>
#include <assert.h>

/*#include "main.h"
#include "main.h"
*/

#define FOOBAR 42

#define rekt(n) (n)*(n)

#define tostr(exp) #exp

#define concat(x,y) x##y

#define checker(exp) \
	if (!(exp))\
{ \
	std::cout << "ERROR!! Assert " << #exp << " failed\n"; \
	std::cout << " on line " << __LINE__ << "\n"; \
	std::cout << " in file " << __FILE__ << "\n";  \
	DebugBreak(); \
	}

int main()
{
	Hello();

	/////////////////////////////////////////////////// 

	int a = 10;

#ifdef FOOBAR
	a = FOOBAR;
#endif

	std::cout << a << std::endl;

	a = 10;

#undef FOOBAR
#ifdef FOOBAR
	a = FOOBAR;
#endif

	std::cout << a << std::endl;

	///////////////////////////////////////////////// 

#line 8 "blqh.c"
	printf("%d %s \n", __LINE__, __FILE__);

	////////////////////////////////////////////////// 

	std::cout << rekt(3) << std::endl;

	////////////////////////////////////////////////// 

	std::cout << tostr(Shall we play a game) << std::endl;


	////////////////////////////////////////////////// 

	int xy = 420;

	std::cout << concat(x,y) << std::endl;

	//////////////////////////////////////////////

	//checker(xy != 420);
	//assert(xy != 420);

	std::cout << rekt(17) << std::endl;

#ifdef FOOBAR
#error "This code should not compile"
#endif

	return 0;
}