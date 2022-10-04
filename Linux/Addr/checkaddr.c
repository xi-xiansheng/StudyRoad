#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int g_val = 0;
int g_uninit_val;
    

//int main(int argc, char *argv[], char *env[])
int main()
{
    printf("g_val is:%d, addr is:%p\n", g_val, &g_val);
    pid_t ret = fork();
    if(ret == 0)
    {
        //子进程
        printf("i am child:g_val  is:%d, addr is:%p\n", g_val, &g_val);
        sleep(5);
        g_val = 100;
        printf("i am child:g_val  is:%d, addr is:%p\n", g_val, &g_val);
    }
    else if(ret > 0)
    {
        //父进程
        printf("i am father:g_val is:%d, addr is:%p\n", g_val, &g_val);
        sleep(10);
        printf("i am father:g_val is:%d, addr is:%p\n", g_val, &g_val);
    }
    else
    {
        perror("fork failed\n");
        exit(1);
    }
    //printf("code addr is:           %p\n", main);
    //const char *r = "hello!\n";
    //printf("read only addr is:      %p\n", r);
    //printf("global addr is:         %p\n", &g_val);
    //printf("global uninit addr is:  %p\n", &g_uninit_val);
    //char *q1 = (char *)malloc(10);
    //char *q2 = (char *)malloc(10);
    //char *q3 = (char *)malloc(10);
    //printf("heap addr is:           %p\n", q1);
    //printf("heap addr is:           %p\n", q2);
    //printf("heap addr is:           %p\n", q3);
    //int a = 1;
    //static int b = 2;
    //int c = 3;
    //printf("stack addr is:          %p\n", &a);
    //printf("static: stack addr is:  %p\n", &b);
    //printf("stack addr is:          %p\n", &c);
    //printf("args addr is:           %p\n", argv[0]);
    //printf("args addr is:           %p\n", argv[argc - 1]);
    //printf("env addr is:            %p\n", env[0]);
    return 0;
}
