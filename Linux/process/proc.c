#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
    printf("i am a process, ppid id:%d\n",getppid());
    printf("%s\n", getenv("PATH"));
    printf("%s\n", getenv("USER"));
    printf("%s\n", getenv("MYVALUE"));
    printf("%s\n", getenv("SHELL"));
    return 0;
}
