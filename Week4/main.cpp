#include <iostream>
#include <fstream>

int main()
{
	/*std::ifstream in("rekt.txt");

	char foo;

	while (true)
	{
		in.get(foo);

		if (in.eof())
			break;

		std::cout << foo << std::endl;
	}*/

	std::ofstream out("goten.dat", std::ios::binary);

	if (!out)
		std::cout << "get rekt brah" << std::endl;

	int foo = 42;
	int bar = 322;
	out.write((char*)&foo, sizeof(int));
	out.write((char*)&bar, sizeof(int));

	out.close();

	std::ifstream input("goten.dat", std::ios::binary);
	int rekt;

	if (!out)
		std::cout << "get rekt brah" << std::endl;

	while (true)
	{
		input.read((char*)&rekt, sizeof(int) +1);
		if (input.eof())
		{
			std::cout << "get rekt brah" << std::endl;
			break;
		}

		std::cout << rekt << std::endl;
	}

	input.close();

	return 0;
}