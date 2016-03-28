#include <iostream>
#include <fstream>
#include "Header.h"

const char fileName[] = "failche.dat";


#define FILENAME "failche.dat";


struct shitDataStruct
{
	char* str;
	int foo;
	double bar;
};

struct plainDataStruct
{
	char str[255];
	int foo;
	double bar;
};


bool readInput(std::ifstream& input, plainDataStruct*& pArr, int& Count)
{
	if (!input)
		return false;

	input.seekg(0, std::ios::end);

	int size = input.tellg();


	input.seekg(0, std::ios::beg);

	Count = size / sizeof(plainDataStruct);

	pArr = new (std::nothrow) plainDataStruct[Count];

	input.read((char*)pArr, size);

	return true;
}


int main()
{
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
		b[i].bar = 27.3;
	}

	// работа със структурите 

	out.write((char*)&b, sizeof(plainDataStruct) * 15);

	out.close();

	std::ifstream input(fileName, std::ios::binary);

	plainDataStruct* pData;

	int structCounter;


	readInput(input, pData, structCounter);

	/*if (!input)
		return 1;

	input.seekg(0, std::ios::end);
	int size = input.tellg();

	input.seekg(0, std::ios::beg);

	structCounter = size / sizeof(plainDataStruct);

	pData = new (std::nothrow) plainDataStruct[structCounter];

	input.read((char*)pData, size);*/


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