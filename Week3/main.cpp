#include <iostream>
#include <fstream>
#include "Tasks.h"


int main()
{
	std::ifstream input("neshto.txt");

	char buff[200];
	if (!input)
		std::cout << "cant read" << std::endl;

	while (!input.eof())
	{

		input >> buff;

		// проверяваме дали потока е в добро състояните 
		if (!input.good())
		{
			// проверка дали нещо не е счупено безвъзвратно 
			if (input.bad())
			{
				std::cout << "PROBLEM!!!" << std::endl;
				break;
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

				// целта на това continue е да 
				// бъдат пропуснати всякакви действия 
				// с данните, които е трябвало да бъдат 
				// прочетени 
				continue;
			}
		}

			std::cout << buff << std::endl;
	}

	input.close();

	return 0;
}