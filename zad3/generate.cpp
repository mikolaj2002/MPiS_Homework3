#include <iostream>
#include <random>
#include <ctime>
#include <fstream>

int main()
{
    std::mt19937 urbg {(unsigned int)time(NULL)};  
    std::uniform_int_distribution<int> distr1 {0, 1};

    std::ofstream f("data.txt");
    
    for (int n = 100; n <= 10000; n *= 10)
    {
        for (int k = 0; k < 5000; k++)
        {
            int position = 0;
            int D[n];
            int L = 0;

            for (int i = 0; i < n; i++)
            {
                int step = distr1(urbg) == 0 ? -1 : 1;
                position += step;
                
                if (position > 0 || (position == 0 && step == -1))
                {
                    D[i] = 1;
                    L++;
                }
                else
                    D[i] = 0;
            }

            double P = L * 1.0 / n;

            f << n << ";" << k << ";" << P << std::endl;
        }
    }
    
    f.close();

    return 0;
}