#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i = 0; i < 3; i++)
    {
        printf("commad:%d\n", i);
    }
    printf("getenv:VALUE=%s\n", getenv("VALUE"));
    return 0;
}
