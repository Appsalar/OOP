#ifndef CIGAR_H
#define CIGAR_H
#include <fstream>
#include <iostream>

const int MAX_NAME_SIZE = 73;


struct Cigar
{
	char name[MAX_NAME_SIZE];
	double price;
};


void checkFileExist(const char* fileName);
bool readFromFile(std::ifstream& input, Cigar*& pArr, int& Count);
bool writeToFile(std::ofstream& output, Cigar* pArr, int Count);

#endif // CIGAR_H
