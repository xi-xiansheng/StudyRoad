#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    //execl("/usr/bin/ls", "ls", "-l", "-i", NULL);
    //execlp("ls", "ls", "-l", "-i", NULL);
    //char *const myargv[] = {"ls", "-a", "-l", "-i", NULL};
    //execv("/usr/bin/ls", myargv);
    //execvp("ls", myargv);
    char *const argv[] = {"mycmd", NULL};
    char *const myenv[] = {"VALUE=nihao", NULL};
    //execle("./mycmd", "mycmd", NULL, myenv);
    //execve("./mycmd", argv, myenv);
    execvpe("mycmd", argv, myenv);

    return 0;
}
