#include "Header.h"

bool readInput(std::ifstream& input, plainDataStruct*& pArr, int& Count)
{
	if (!input)
		return false;

	// курсорът е изпратен на края на файла
	input.seekg(0, std::ios::end);

	// големината на файла в байтове
	int size = input.tellg();

	// курсорът е върнат в началото така че 
	// да може да чете 
	input.seekg(0, std::ios::beg);

	// тъй като структурата е POD 
	// значи всички структури във файла имат 
	// еднакъв размер и лесно може да бъде взет
	// броя им
	Count = size / sizeof(plainDataStruct);

	// заделяне на памет за структурите във файла 
	pArr = new (std::nothrow) plainDataStruct[Count];

	// четене на целия файл в заделения масив 
	input.read((char*)pArr, size);

	return true;
}