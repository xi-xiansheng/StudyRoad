#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int main()
{
    if(fork() == 0)
    {
        cout << "i am child, pid is: " << getpid() << ",ppid is:" << getppid() << endl;
        exit(1);
    }
    cout << "i am father,pid is: " << getpid() << ",ppid is: " << getppid() << endl;
    sleep(30);
    return 0;
}


