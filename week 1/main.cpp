#include <iostream>


#include <iostream>


void print();


#ifndef CONST_H
#define CONST_H

const int abc = 42;


#endif 

#ifndef CONST_H
#define CONST_H

const int abc = 42;


#endif 



#define square(n) (n)*(n)

#define square_wrong(n) \
					n*n

#define min(n,m)\
				if(n>m)\
				{\
					std::cout<< m<< std::endl;\
				}\
				else\
					std::cout<< n<< std::endl;


#define toStr(exp) #exp

#define checker(exp)\
				if(exp)\
				{\
					std::cout<< "True:"<< #exp<< std::endl;\
				}\
				else\
					std::cout<< "not true:"<< #exp<< std::endl;


#define concat(x, y) x##y


int main()
{



	std::cout << __FILE__ << std::endl;
	std::cout << __LINE__ << std::endl;
#line 7 "az sym gotin"

	
	std::cout << __FILE__ << std::endl;
	std::cout << __LINE__ << std::endl;

	std::cout << __DATE__ << std::endl;
	std::cout << __TIME__ << std::endl;

	min(3, 4);


	std::cout << square_wrong(2 + 2) << std::endl;

	std::cout << square(2 + 2) << std::endl;

	std::cout << toStr(akd jasfh ausfhs eiofaljfhas klask) << std::endl;

	checker(1 < 0 && 42 < 78);


	int ab = 1231420;
	double foo = 420.42;

	std::cout << ab << std::endl;

	std::cout << concat(a,b) << std::endl;

	std::cout << concat(fo, o) << std::endl;



	print();

	return 0;
}