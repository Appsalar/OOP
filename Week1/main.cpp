// ****
//  ПОЧТИ ВСИЧКО В ТОЗИ ФАЙЛ Е ДЕМОНСТРАЦИЯ 
//  НА ЛОШИ ПРАКТИКИ, КОИТО НЕ Е ДОБРЕ 
//  ДА ПОЛЗВАТЕ 
// ***

#include <iostream>

#include <iostream>

// замества съдържанието на Header.h
// като същите неща прави и за стандартните библиотеки
#include "Header.h" 
/*
#ifndef HEADER
#define HEADER

#include <iostream>


void print();


#endif // HEADER
*/

#include "Const.h" // замества съдържанието на Const.h
/*
#ifndef CONST_H
#define CONST_H

const int abc = 42;


#endif 
*/


#include "Const.h" // замества съдържанието на Const.h
/*
#ifndef CONST_H
#define CONST_H

const int abc = 42;


#endif
*/

// замества всяко срещане на PI с 3.14159
#define PI 3.14159 

// изчислява квадрат
#define square(n) (n)*(n)

// грешен квадрат
#define square_wrong(n) \
					n*n

#define min(n,m)\
				if(n>m)\
				{\
					std::cout<< m<< std::endl;\
				}\
				else\
					std::cout<< n<< std::endl;

// превръща подадения аргумент в стринг
#define toStr(exp) #exp

// печата подадения аргумент и казва дали 
// е истина или лъжа
#define checker(exp)\
				if(exp)\
				{\
					std::cout<< "True:"<< #exp<< std::endl;\
				}\
				else\
					std::cout<< "not true:"<< #exp<< std::endl;


// обратната наклонена черта '\' \
указва, че даденият израз продължава \
и на следващия ред , като освен за макроси \
може да бъде използвано за коментари, стрингове \
и т.н. ,но ако бъде използвано за "//" коментари \
компилаторът ще пищи, но все пак кодът ще се компилира


// слепя подадените аргументи
#define concat(x, y) x##y


int main()
{



	std::cout << __FILE__ << std::endl; // печата името на файла
	std::cout << __LINE__ << std::endl; // печета реда, на който се намира

// предефинира __LINE__ и __FILE__
#line 7 "az sym gotin"

	
	std::cout << __FILE__ << std::endl; // печата предефинираното име
	std::cout << __LINE__ << std::endl; // печата реда спрямо #line

	std::cout << __DATE__ << std::endl; // печата датата
	std::cout << __TIME__ << std::endl; // печата часа 

	min(3, 4);


	std::cout << square_wrong(2 + 2) << std::endl;

	std::cout << square(2 + 2) << std::endl;

	std::cout << toStr(akd jasfh ausfhs eiofaljfhas klask) << std::endl;

	checker(1 < 0 && 42 < 78);


	int ab = 1231420;
	double foo = 420.42;

	std::cout << ab << std::endl;

	// същото като 
	//std::cout << ab << std::endl;
	std::cout << concat(a,b) << std::endl;

	// същото като 
	//std::cout << foo << std::endl;
	std::cout << concat(fo, o) << std::endl; // 

	// същото като 
	// float chislo;
	concat(flo, at) chislo; // дефинираме float с име chislo и работи Kappa
	chislo = 32.2f;

	std::cout << chislo << std::endl;

	print();

	return 0;
}

// ако долното бъде разкоментирано 
// и бъдат изтрити ; и } програмата 
// все пак ще се компилира 

//#include "endfile.h"
