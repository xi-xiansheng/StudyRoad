#include <iostream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main()
{
    //while(true){
        //printf("this process pid is: %u,ppid is: %u",getpid(), getppid());
        //cout << "this process pid is: " << getpid() << " ppid is:" << getppid() << endl;
        //sleep(1);
    //}
        //cout << "this process pid is:    " << getpid() << endl;
        //cout << "ppid is:                " << getppid() << endl;
        //cout << "uid is:                 " << getuid() << endl;
        //cout << "euid is:                " << geteuid() << endl;
        //cout << "gid is:                 " << getgid() << endl;
        //cout << "egid is:                " << getegid() << endl;
   // while(true){
   //     sleep(1);
   // }
    
    //fork();
    //while(true)
    //{
    //    cout << "i am a process, pid is: " << getpid() << " ,ppid is: " << getppid() << endl;
    //    sleep(1);
    //
    //}
    while(true)
    {
        cout << "this is a process, pid is: " << getpid() << ",ppid is: " << getppid() << endl;
        sleep(1);
    }
    //pid_t ret = fork();
    //if(ret == 0)
    //{
    //    //子进程
    //    while(true)
    //    {
    //        cout << "i am child,pid is: " << getpid() << ",ppid is: " << getppid() << endl;
    //        sleep(1);
    //    }
    //}
    //else if(ret > 0)
    //{
    //    //父进程
    //    while(true)
    //    {
    //        cout << "i am father, pid is: " << getpid() << ",ppid is: "<< getppid() << endl;
    //        sleep(1);
    //    }
    //}
    //else{
    //    cerr << "fork failed " << endl;
    //}

    return 0;
}
