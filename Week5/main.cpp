#include <iostream>
#include <fstream>
#include "Header.h"

const char fileName[] = "failche.dat";

#define FILENAME "failche.dat";


int main()
{
	// закоментираният код е пример как можем 
	// да запишем не POD структура 
	/*A a;

	std::ofstream out(fileName, std::ios::binary);

	//out.write((char*)&a, sizeof(a));

	int size = strlen(a.str);


	out.write((char*)&size, sizeof(size));
	out.write((char*)&a.str, size);
	out.write((char*)(&a + sizeof(void*)), sizeof(a) - sizeof(void*));*/

	std::ofstream out(fileName, std::ios::binary);

	plainDataStruct b[15];

	for (int i = 0;i < 15;++i)
	{
		strcpy(b[i].str, "Armqnov gleda");
		b[i].foo = 1337;
		b[i].bar = neshto;
	}

	// работа със структурите 

	out.write((char*)&b, sizeof(plainDataStruct) * 15);

	out.close();

	std::ifstream input(fileName, std::ios::binary);

	plainDataStruct* pData;

	int structCounter;

	readInput(input, pData, structCounter);

	for (int i = 0;i < structCounter;++i)
	{
		std::cout << pData[i].str << std::endl;
		std::cout << pData[i].foo << std::endl;
		std::cout << pData[i].bar << std::endl;
		std::cout << std::endl;
	}

	delete[] pData;

	input.close();

	return 0;
}