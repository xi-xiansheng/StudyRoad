#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 32
#define NUM 128 

char commad_line[NUM];
char* commad_parase[SIZE];

int main()
{

        while(1)
        {
                memset(commad_line, 0, sizeof(commad_line));
                printf("[xcs101@my_shell]:");
                fflush(stdout);

                if(fgets(commad_line, NUM - 1, stdin))
                {
                    commad_line[strlen(commad_line) - 1] = '\0';
                    commad_parase[0] = strtok(commad_line, " ");
                    int i = 0;
                    while(1)
                    {
                            i++;
                            commad_parase[i] = strtok(NULL, " ");
                            if(commad_parase[i] ==  NULL)
                            {
                                    break;
                            }
                    }
    
                }

                //判断内置命令
                if(strcmp(commad_parase[0], "cd") == 0 && commad_parase[1] == 0)
                {
                        continue;
                }
                if(fork() == 0)
                {
                        execvp(commad_parase[0],commad_parase);
                        exit(-1);
                }
                int status = 0;
                pid_t ret = waitpid(-1, &status, 0);
                if(ret == -1)
                {
                        printf("error\n");
                        break;
                }
                else if(ret > 0 && WIFEXITED(status))
                {
                        printf("Exit Code: %d\n", WEXITSTATUS(status));
                }
                
        }


        return 0;
}
