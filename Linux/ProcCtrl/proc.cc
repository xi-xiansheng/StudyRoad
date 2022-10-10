#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

using namespace std;

static void my_exit1(void)
{
    printf("handler1 is done\n");
}

static void my_exit2(void)
{
    printf("handler2 is done\n");
}

int main()
{
    printf("nihao");
    _exit(0);
//    if(atexit(my_exit1) != 0)
//    {
//        printf("hanler1 failed\n");
//        exit(1);
//    }
//    if(atexit(my_exit2) != 0)
//    {
//        printf("hanler2 failed\n");
//        exit(2);
//    }
//    printf("main is done\n");
    //for(int i = 0; i < 140; i++)
    //{
        //cout << i << ": " << strerror(i) << endl;
        //printf("%3d: %s\n", i, strerror(i));
    //}
    //return 0;
    //exit(-1);
//    return (0);
}
