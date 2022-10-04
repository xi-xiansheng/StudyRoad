#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

int main(int argc, char* argv[], char *env[])
{
    //char **environ;
    for(int i = 0; env[i]; i++)
    {
        cout << environ[i] << endl;
    }
   // for(int i = 0; i < argc; i++)
   // {
   //     cout << argv[i] << endl;
   // }

//    cout << "i am a process, ppid id:" << getppid() << endl;
//    cout << getenv("MYVALUE")<< endl;
//    cout << getenv("PATH") << endl;
//    cout << getenv("SHELL") << endl;
//    cout << getenv("USER") << endl;
//
    return 0;
}
