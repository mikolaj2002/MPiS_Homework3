#include <iostream>
#include <random>
#include <ctime>
#include <fstream>

int main()
{
    // Mersenne Twister random engine:
    std::mt19937 urbg {(unsigned int)time(NULL)};  
    // generate random ints ∈ [1,6]
    std::uniform_int_distribution<int> distr1 {0, 1};

    std::ofstream f("out.txt");
    for (int i = 0; i < 2000000; i++)
        f << distr1(urbg);
    f.close();

    return 0;
}