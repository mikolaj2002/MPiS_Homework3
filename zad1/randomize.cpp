#include <iostream>
#include <random>
#include <fstream>

int main()
{
    std::mt19937 mt{};

    std::ofstream f("out.txt");
	for (int count{0}; count <= 2000000; count++)
	{
		f << mt() % 2;
	}
    f.close();

    return 0;
}