#include <stdio.h>
#include <unistd.h>
#include <pwd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>

#define NUM 128
#define SIZE 32

char commad_line[NUM];
char *commad_parse[SIZE];

void PathStro(char *path)
{
    int i = strlen(path) - 1;
    while(i >= 0 && path[i] != '/')
    {
        i--;
    }
    if(i == 0)
    {
        ;
    }
    else if(i > 0)
    {
        strcpy(path, path + i + 1);
    }
    else 
    {
        perror("file path get error\n");
        exit(1);
    }           
}

int main()
{
    char path[50];
    char hostname[50];
    while(1)
    {
        //重置
        memset(commad_line, '\0', sizeof(commad_line));
        memset(path, '\0', sizeof(path));
        memset(hostname, '\0', sizeof(hostname));
        if(getcwd(path, sizeof(path) - 1))
        {   
            //获取当前路径
            PathStro(path);
        }
        //获取主机名
        //gethostname(hostname, sizeof(hostname) - 1);
        //获取用户信息
        struct passwd *ps = getpwuid(getuid());
        //printf("[%s@%s %s]$ ", ps->pw_name, hostname, path);
        printf("[%s@myhost %s]$ ", ps->pw_name, path);
        fflush(stdout);
        if(fgets(commad_line, NUM - 1, stdin))
        {   
            //从标准输入读取
            commad_line[strlen(commad_line) - 1] = '\0';
            //分割命令
            int index = 0;
            commad_parse[index] = strtok(commad_line, " ");
            while(1)
            {
                index++;
                commad_parse[index] = strtok(NULL, " ");
                if(commad_parse[index] == NULL)
                    break;
            }
            //printf("commad[0]:%s", commad_parse[0]);
            //判断内置命令
            if(strcmp(commad_parse[0], "cd") == 0 && chdir(commad_parse[1]) == 0)
            {
               continue;
            }
            //子进程替换执行
            pid_t pid = fork();
            if(pid == 0)
            {
                //exec* 采用vp     
                execvp(commad_parse[0], commad_parse);
                exit(1);
            }
            else if(pid < 0) 
            {
                perror("fork faild...\n");
                return 1;
            }
            int status = 0;
            int ret = waitpid(-1, &status, 0);
            if(ret > 0 && WIFEXITED(status))
            {
                //等待成功
                //printf("Exit code:%d\n", WEXITSTATUS(status));
            }
        }   
    }
        
    return 0;
}
