#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t childs[5];
    //for(int i = 0; i < 5; i++)
    //{
    //    pid_t id = fork();
    //    if(id == 0)
    //    {
    //        //child
    //        printf("child is running...pid is:%d, ppid is:%d\n", getpid(), getppid());
    //        //sleep(2);
    //        sleep(3);
    //        if(i == 4)
    //        {
    //            //子进程异常退出
    //            //int *p = 0x11223344;
    //            //*p = 123;
    //        }
    //        exit(i);
    //    }
    //    childs[i] = id;
    //}
    pid_t pid = fork();
    if(pid == 0)
    {
        printf("child is running...pid is:%d, ppid is:%d\n", getpid(), getppid());
        sleep(5);
        exit(0);
    }
    while(1)
    {
        int status = 0;
        pid_t ret = waitpid(-1, &status, WNOHANG);
        if(ret == 0)
        {
            printf("father is waiting...\n");
            sleep(1);
        }
        else 
        {
            printf("waiting success\n");
            break;
        }
    }
    //for(int i = 0; i < 5; i++)
    //{
    //    int status = 0;
    //    //pid_t ret = waitpid(childs[i], &status, 0);
    //    pid_t ret = waitpid(childs[i], &status, WNOHANG);
    //    if(ret > 0)
    //    {
    //        //等待正常
    //        if(WIFEXITED(status)) 
    //        {
    //            //正常退出
    //            printf("child:%d qiut normal, exit code:%d\n", childs[i], WEXITSTATUS(status));
    //        }
    //        else
    //        {
    //            printf("child:%d qiut abmormal, sig:%d\n", childs[i], WIFSIGNALED(status));
    //        }
    //    }
    //    else if(ret == 0)
    //    {
    //        printf("father is waiting...\n");

    //    }
    //    //if(ret > 0)
    //    //{
    //    //    //等待正常
    //    //    int sig = status & 0x7F;
    //    //    int code = (status >> 8) & 0xFF;
    //    //    if(sig == 0)
    //    //    {
    //    //        //正常退出
    //    //        printf("child:%d qiut normal, exit code:%d\n", childs[i], code);
    //    //    }
    //    //    else
    //    //    {
    //    //        printf("child:%d qiut abmormal, sig:%d\n", childs[i], sig);
    //    //    }
    //    //}
    //}


//    fork();
//    printf("hello\n");
//    exit(0);
//}
    //pid_t pid = fork();
    //if(pid == 0)
    //{
    //    //child
    //    int count = 3;
    //    while(count)
    //    {
    //        printf("child is running...pid:%d, ppid:%d, count:%d\n", getpid(), getppid(), count--);
    //        sleep(1);
    //    }
    //    //模拟异常退出
    //    //int *p = 0x11223344;
    //    //*p = 1234;
    //    printf("child qiut...\n");
    //    exit(0);
    //}
    //sleep(5);
    //int status = 0;
    //pid_t ret = waitpid(-1, &status, 0);
    //if(ret > 0)
    //{
    //    //等待正常
    //    int code = (status >> 8) & 0xFF;
    //    int sig = status & 0x7F;
    //    if(sig == 0)
    //    {
    //        //正常退出
    //        printf("child qiut normal\n");
    //        printf("exit code:%d\n", code);
    //    }
    //    else
    //    {
    //        printf("child qiut abnormal\n");
    //        printf("sig:%d\n", sig);
    //    }
    //}

//    pid_t pid = fork();
//    if(pid == 0)
//    {
//        //child
//        int count = 3;
//        while(count)
//        {
//            printf("child is running...pid:%d, ppid:%d, count:%d\n", getpid(), getppid(), count--);
//            sleep(1);
//        }
//        sleep(5);
//        printf("child qiut...\n");
//        exit(0);
//        //exit(45);
//    }
//    sleep(5);
//    int status = 0;
//    //pid_t ret = waitpid(-1, NULL, 0);
//    pid_t ret = waitpid(-1, &status, 0);
//    int code = (status >> 8) & 0xFF;
//    int sig = status & 0x7F;
//    printf("father wait done... ret:%d, code:%d, sig:%d, pid:%d\n", ret, code, sig, getpid());
//    sleep(2);
//
    //pid_t pid = fork();
    //if(pid < 0)
    //{
    //    perror("fork error\n");
    //    return 1;
    //}
    //else if(pid == 0)
    //{
    //    //child
    //    int count = 3;
    //    while(count)
    //    {
    //        printf("child is running..., count: %d, pid is:%d\n", count--, getpid());
    //        sleep(1);
    //    }
    //    printf("child qiut...\n");
    //    exit(0);
    //}
    //else
    //{
    //    //father
    //    sleep(6);
    //    printf("father is waiting...\n");
    //    pid_t ret = wait(NULL);
    //    sleep(3);
    //    printf("waiting success, ret is %d\n", ret);
    //}

    return 0;
}
