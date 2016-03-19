#include <iostream>
#include <fstream>

// при този вариант на фукнцията се подава 
// като аргумент псевдоним на поток 
// и е важно потокът да бъде затварян в 
// същия scope, в който е отворен
void read(std::ifstream& input)
{
	char buff[255];
	int a;

	// действието е същото като четенето 
	// в main()
	input.read((char*)&a, sizeof(int));
	input.read(buff, a);
}


// при този вариант на функцията се подава 
// име на файл и локално се създава поток, 
// с който да бъде четено от файла 
void read(const char* fileName)
{
	std::ifstream input(fileName);

	char buff[255];
	int a;

	// действието е същото като четенето 
	// в main()
	input.read((char*)&a, sizeof(int));
	input.read(buff, a);

	input.close();
}

int main()
{
	std::ofstream out;

	// указваме, чв файлът ще е бинарен
	out.open("neshto.dat", std::ios::binary);

	int foo = 42;
	int bar = 322;

	// за записване в бинарен файл трябва да 
	// бъде подаден начален адрес и размер в 
	// байтове на блока памет, който ше бъде 
	// записан
	out.write((char*)&foo, sizeof(foo));
	out.write((char*)&bar, sizeof(int));

	char str[42] = "Armqnov gleda";

	int size = strlen(str) + 1;

	// за записване на стринг първо записваме 
	// дължината на стринга, а след това самия стринг 
	out.write((char*)&size, sizeof(size));
	out.write(str, size);

	out.close();



	// ЗАБЕЛЖКА с кода по долу ще бъдат прочетени само 
	// записаните по горе ст-ти, проверките правени за текстови 
	// файлове попринцип трябва а бъдат правени и за бинарни 
	std::ifstream input("neshto.dat", std::ios::binary);

	// чете двете записани числа
	input.read((char*)&bar, sizeof(int));
	input.read((char*)&foo, sizeof(int));


	char buff[255];
	int a;

	// за четене на стринг първо се прочитат 
	// 4 байта за дължината, която е записана като int 
	input.read((char*)&a, sizeof(int));

	// а след това за самият стринг се четат толкова 
	// байта колкото са прочетени с последното четене 
	input.read(buff, a);

	std::cout << "Length: " << a << std::endl;
	std::cout << "String: " << buff << std::endl;

	input.close();

	return 0;
}