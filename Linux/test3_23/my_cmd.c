#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
    for(int i = 5; i >= 0; i--)
    {
            printf("mycmd : %d \n", i);
            sleep(1);
    }
    printf("getenv -> MYENV: %s", getenv("MYENV"));
    return 0;
}
