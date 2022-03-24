#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
        pid_t id = fork();
        if(id == 0)
        {
                //child
                printf("i am child, pid: %d  ppid:%d \n",getpid(), getppid());
                printf("my process begin\n");
                sleep(1);
                //进程替换
                const char*arg = "ls";
                //execl("/usr/bin/ls", "ls", "-a", "-l", NULL);
                execlp("ls", arg, "-a", "-l", NULL);
                printf("child quit\n");
                exit(10);

        }
        int status = 0;
        pid_t ret = waitpid(id, &status, 0);
        if(ret == -1)
        {
                printf("wait error\n");
        }
        if(ret > 0)
        {
                printf("wait success\n");
        }
        

        return 0;
}




