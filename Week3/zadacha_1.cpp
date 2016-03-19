#include "Tasks.h"
#include <fstream>
#include <iostream>


// при тази реализация четенето става 
// по същия начин, по който се четат числа 
// със стандартните потоци и се записват в 
// int-ове, проблемът е, че за стринг като "123asd" 
// ще бъде прочетено 123 вместо да бъде отхвърлено 
// като невалидно 
void task1A()
{
	std::ifstream input("numbers.txt");

	if (!input)
		std::cout << "Can't open file" << std::endl;

	while (true)
	{
		int num;
		char buff[255];

		input >> num;

		// проверяваме дали потока е в добро състояните 
		if (!input.good())
		{
			// проверка дали нещо не е счупено безвъзвратно 
			if (input.bad())
			{
				std::cout << "PROBLEM!!!" << std::endl;
				return;
			}

			// проверка за край на файла 
			if (input.eof())
			{
				// може края на файла да е стигнат, 
				// но нищо да не е прочетено
				if (input.fail())
					break;
			}

			// ако четенето не е успяло трябва 
			// да се изчистят, за да може да се 
			// прочете отново 
			if (input.fail())
			{
				input.clear();

				// след като четенето е пропаднало 
				// пойнтерът стои остава на след последния 
				// символ, който е успял да прочете 
				// и за да може да се прочете число 
				// със следващото четене, четем 
				// в char буфер, така че стрингът 
				// предизвикал проблем да не бъде четен 
				// отново, иначе се получава безкраен цикъл 
				input >> buff;
				continue;
			}
		}

			std::cout << num << std::endl;
	}

	input.close();
}


// Алтернативен вариант - четем всичко като 
// стрингове и превръщаме числата от стрингове 
void task1B()
{
	std::ifstream input("numbers.txt");

	if (!input)
		std::cout << "Can't open file" << std::endl;

	while (true)
	{
		char buff[255];

		input >> buff;

		// проверяваме дали потока е в добро състояните 
		if (!input.good())
		{
			// проверка дали нещо не е счупено безвъзвратно 
			if (input.bad())
			{
				std::cout << "PROBLEM!!!" << std::endl;
				return;
			}

			// проверка за край на файла 
			if (input.eof())
			{
				// може края на файла да е стигнат, 
				// но нищо да не е прочетено
				if(input.fail())
					break;
			}

			// ако четенето не е успяло трябва 
			// да се изчистят, за да може да се 
			// прочете отново 
			if (input.fail())
			{
				input.clear();
				continue;
			}
		}

		bool numCheck = true;
		for (size_t i = 0;i < strlen(buff);++i)
		{
			// проверка дали в буфера имаме число 
			// по-добре е да се ползват '0' и '9', 
			// а не ascii кодовете на дадените символи 
			// за по-лесно четим код
			if ((buff[i]<'0' || buff[i]>'9') && (i != 0 && buff[i] != '-')) // isdigit(buff[i]) 
			{
				numCheck = false;
				break;
			}
		}

		if (numCheck == true)
		{
			int num;
			num = atoi(buff);// превръщане на числото
			std::cout << num << std::endl;
		}
	}

	input.close();
}