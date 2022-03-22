#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main()
{
    pid_t id = fork();
    if(id == 0)
    {
            int count = 3;
            while(count)
            {
                    printf("child is runnng: %d, pid: %d , ppid: %d\n", count--, getpid(), getppid());
                    sleep(1);
            }
            //int* p = 0x12345678;
            //*p = 0;
            sleep(1);
            printf("child qiut\n");
            exit(10);
    }
    int status = 0;
    while(1)
    {
            pid_t ret = waitpid(id, &status, WNOHANG);
            if(ret == 0)
            {
                    printf("father is do other thing\n");
                    sleep(1);
            }
            else if(ret > 0)
            {
                    //signal & 0x7F exit code & 0xFF
                    printf("wait success,exit code : %d, sig: %d\n", WEXITSTATUS(status), (status >> 8) & 0x7F );
                    break;
            }
            else
            {
                    printf("wait failed\n");
                    break;
            }
    }
    
           
//    int status = 0;
//    pid_t id = fork();
//    if(id == 0)
//    {
//	    int count = 5;
//    	while(count)
//    	{    
//	    	printf("child is running: %d, ppid：%d, pid: %d\n",count--, getppid(), getpid());
//		    sleep(1);
//	    } 
//    }
//    else if(id > 0)
//    {
//	    //wait(&status);
//
//        //	if(status != -1)
//	    //       printf("wait success\n");
//        //	else
//	    //        printf("wait failed\n");
//              
//        //阻塞式等待
//	    int ret = waitpid(id, &status, 0);
//    	if(ret == -1)
//        {
//            printf("调用出错\n");
//        }
//    	else
//        {
//              if(WIFEXITED(status))
//              {
//                     printf("normal quit!\n");
//                     //提取退出码
//                     printf("quit code : %d\n", WEXITSTATUS(status));
//              }
//              else
//              {
//                    printf("exit error\n");
//              }
//        }
//	        printf("wait success\n");
//    }
//    else
//    {
//       perror(NULL);
//    }

   
 // //  pid_t pid = fork();
 // //  if(pid == 0)
 // //  {
 // //
 // //      int count = 5;
 // //      while(count)
 // //      {    
 // //      	printf("child is running: %d, ppid：%d, pid: %d\n",count--, getppid(), getpid());
 // //      	sleep(1);
 // //      } 
 // //  }
 // //  else if(pid > 0)
 // //  {
 // //  	printf("father  is running, ppid：%d, pid: %d\n", getppid(), getpid());
 // //  }
 // //  else
 // //  {
 // //      perror(NULL);
 // //  }



    return 0;
}

