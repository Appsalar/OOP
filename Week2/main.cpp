#include <iostream>
#include "Header.h"
#include <fstream>

using namespace std;

int main()
{
	// в коментарите отстрани е изведената ст-ст 
	cout << sizeof(Date) << endl;        // 12 
	cout << sizeof(Datecompact) << endl; //  4 
	cout << sizeof(foo) << endl;         // 24 
	cout << sizeof(bar) << endl;         // 16 

	// инициализираме поток за писане с името на файла, 
	// в който ще пишем, а като втори аргумент 
	// приема флагове, с които се указват дадени 
	// настройки на потока 
	// с ios::in указваме, че можем да четем от файла 
	// в случая го ползваме, заради seekp() 
	ofstream ofs("random_ime.txt", ios::in);

	// проверяваме дали можем да пишем във файла
	if (!ofs)
		cout << "Can't open file" << endl;

	// ако на потока не е указано, че 
	// може да се чете, seekp() няма да 
	// работи както трябва 
	ofs.seekp(0, ios::end); // местим курсора в края на файла 

	// взимаме позицията на курсора 
	// като в случая е на края на файла, 
	// т.е. взимаме големината на файла в байтове
	int fileSize = ofs.tellp();

	cout << fileSize << endl;

	// пишем някакви неща във файла 
	ofs << "Зайченцето бяло" << endl;
	ofs << "Kappa Shift 77" << endl;



	// is_open() връща true, ako потокът 
	// е отворен и false, ako не е 
	// в случая е отворен
	if (ofs.is_open())
		cout << "The file is opened" << endl;
	else
		cout << "The file is closed" << endl;

	// експлицитно затваряне на потока
	ofs.close();


	if (ofs.is_open())
		cout << "The file is opened" << endl;
	else
		cout << "The file is closed" << endl;;

	return 0;
}