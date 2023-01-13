#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
    srand(time(NULL));

    FILE *f = fopen("out.txt", "w");
    for (int i = 0; i < 2000000; i++)
        fprintf(f, "%d", rand() % 2);
    fclose(f);

    return 0;
}