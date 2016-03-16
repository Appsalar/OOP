#include <iostream>
#include <fstream>
#include "Tasks.h"

void task3A()
{

	char targetWord[255];

	std::cout << "Enter a word: ";
	std::cin >> targetWord;

	std::ifstream in("dumi.txt");

	if (!in)
		std::cout << "Can't open file" << std::endl;

	char buff[255];
	while (in >> buff)
	{
		if (strcmp(buff, targetWord) == 0)
		{
			std::cout << "Found Word" << std::endl;
			return;
		}
	}

	std::cout << "Not found!" << std::endl;
}

void task3B()
{

	char targetWord[255];

	std::cout << "Enter a word: ";
	std::cin >> targetWord;

	std::ifstream in("dumi.txt");

	if (!in)
		std::cout << "Can't open file" << std::endl;

	char buff[255];
	while (true)
	{
		in >> buff;

		if (!in.good())
		{
			if (in.bad())
			{
				std::cout << "PROBLEM!!!" << std::endl;
				return;
			}

			if (in.eof())
			{
				if (in.fail())
					break;
			}

			if (in.fail())
			{
				in.clear();
				continue;
			}
		}

		if (strcmp(buff, targetWord) == 0)
		{
			std::cout << "Found Word" << std::endl;
			return;
		}
	}

	std::cout << "Not found!" << std::endl;
}