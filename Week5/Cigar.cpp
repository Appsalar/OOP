#include "Cigar.h"


void checkFileExist(const char* fileName)
{
	std::ifstream input(fileName, std::ios::binary);

	if (!input.is_open())
	{
		std::ofstream out(fileName, std::ios::binary);
		out.close();
	}

	input.close();
}

bool readFromFile(std::ifstream& input, Cigar*& pArr, int& Count)
{
	if (!input)
		return false;

	input.seekg(0, std::ios::end);
	int size = input.tellg();

	input.seekg(0, std::ios::beg);

	Count = size / sizeof(Cigar);

	pArr = new (std::nothrow) Cigar[Count];

	input.read((char*)pArr, size);
	return true;
}

bool writeToFile(std::ofstream& output, Cigar* pArr, int Count)
{
	if (!output)
		return false;

	output.write((const char*)pArr, Count * sizeof(Cigar));

	return true;
}


