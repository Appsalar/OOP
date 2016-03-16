#include <iostream>
#include <fstream>
#include "Tasks.h"

void task2A()
{
	std::ifstream in("dumi.txt");

	if (!in)
		std::cout << "Can't open file" << std::endl;

	int cnt = 0;
	char buff[255];

	// докато може да чете успешно 
	// увеличаваме броячът 
	while (in >> buff)
		++cnt;

	std::cout << "Words counter = " << cnt << std::endl;
}

void task2B()
{
	std::ifstream in("dumi.txt");

	if (!in)
		std::cout << "Can't open file" << std::endl;

	int cnt = 0;
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

		++cnt;
	}
	std::cout << "Words counter = " << cnt << std::endl;
}