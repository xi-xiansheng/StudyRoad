#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define NUM 102

int main()
{
    const char* op = "-/\\|";
    char bar[NUM + 2];
    memset(bar, 0, sizeof(bar));
    int count = 0;
    while(count <= 100)
    {
        bar[count] = '#';
        printf("[%-100s][%d%%][%c]\r", bar, count, op[count % 4]);
        count++;
        usleep(100000);
        fflush(stdout);
    }
    printf("\n");
    return 0;
}

