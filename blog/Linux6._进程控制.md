[TOC]
------
# 1. 进程创建

&emsp;&emsp;我们知道，进程创建有两种方式：1. 命令行启动命令 2. `fork()`子进程。接下来我们就来谈谈`fork()`。

## `fork()`函数初识

&emsp;&emsp;`fork()`从已存在进程中创建一个新进程。子进程为新进程，父进程为原进程。在上一节进程概念中我们提及到`fork()`函数。

```shell
#include <unistd.h>
#include <sys/types.h>
pid_t fork(void);
返回值:子进程中返回值为0，父进程返回子进程id，出错返回-1
```
&emsp;&emsp;所有`fork()`出来的子进程几乎但不完全与父进程相同。子进程得到与父进程用户级虚拟地址空间相同的（但是独立的）一份拷贝，包括文本、数据和 bss 段、堆以及用户栈。子进程还获得与父进程任何打开文件描述符相同的拷贝，这就意味着当父进程调用`fork()`时，子进程可以读写父进程中打开的任何文件。但是其中的属性数据，如子进程的调度时间，pid，ppid，用户级页表、子进程不会继承父进程的内存锁、子进程会重新设置进程资源利用率和 CPU 计时器、与其他进程的链接关系等都要重新设置，不过其他大部分信息都是以父亲为模板的。
&emsp;&emsp;调用`fork()`：创建子进程，本质上系统多了一个进程，多了一套与进程相关的数据结构。
进程调用fork，当控制转移到内核中的`fork()`代码后，内核将做：

-   分配新的内存块和内核数据结构给子进程
-   将父进程部分数据结构内容拷贝至子进程
-   添加子进程到系统进程列表当中
-   `fork()`返回，开始调度器调度  

## `fork()`函数返回值

&emsp;&emsp;`fork()`函数是有趣的也是令人迷惑的，因为它调用一次返回两次：一次是在调用进程（父进程）中，一次是在新创建的子进程中。在父进程中，`fork()`返回子进程的PID，在子进程中，`fork()`返回 0 。因为子进程的 PID 总是非零的，返回值就提供一个明确的方法来分辨程序是在父进程还是在子进程中执行。
```c
pid_t pid = fork();
```
&emsp;&emsp;此时再看上述代码，思考基于上一节的理解，此时我们有如下两种理解方式：

1.   `fork()`既然是一个函数，那么它必然有自己的业务逻辑。也就是说，在`fork()`这个函数当中，一定会为子进程创建pcb，创建进程地址空间，创建页表，构建组织关系，子进程pcb链入调度队列中等操作，并且在执行**return语句**之前子进程就已经被创建出来了，创建动作是由父进程执行。
     ![fork()函数](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151227402.png)
     同时这个pid变量是由父进程创建的，当执行返回语句的时候，其本质就是写入这个变量。既然此时子进程已经存在，这个时候就会发生**写时拷贝**，由此父子进程当中都有自己的pid。于是一个变量名，内容就是不同的，**本质就是父子页表映射数据到了不同的物理内存区域**！
     换言之，在`fork()`函数内部执行**return**语句之前，子进程就已经创建完毕了，那么之后的**return**语句不仅父进程需要执行，子进程也同样需要执行，这就解释了`fork()`函数为何有两个返回值。
2.   上一节我们提到，子进程创建后，代码共享数据各自私有一份。那么再执行`return`前，子进程便已经被创建出来，因此会执行两次`return`语句。

## 写时拷贝

**什么是写时拷贝(copy-on-write)**
&emsp;&emsp;内核只为新生成的子进程创建虚拟空间结构，它们来复制于父进程的虚拟结构，但是不为这些段分配物理内存，它们共享父进程的物理空间，当父子进程中有更改相应段的行为发生时，再为子进程相应的段分配物理空间。
![写时拷贝](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151227667.png)
**为什么要有写时拷贝**

-   进程独立性。多进程运行，需要独享各种资源，多进程运行期间互不干扰，不能让子进程的修改影响到父进程。
-   并不是所有的数据父子进程都会进行写入。不需要写入(即只读的)，此时拷贝没有意义，并且占用物理内存空间，浪费系统资源（cpu资源）。
-   `fork()`时，需创建对应的数据结构，若将数据拷贝一份，一定会使得`fork()`本身效率的降低。此外，`fork()`本身就是向OS申请资源，当资源过大或资源有限时，其容易导致`fork()`失败。

&emsp;&emsp;传统的`fork()`系统调用直接把所有的资源复制给新创建的进程。这种实现过于简单并且效率低下, 因为它拷贝的数据也许井不共享，更糟的情况是，如果新进程打算立即执行一个新的映像，那么所有的拷贝都将前功尽弃。Linux的`fork()`使用写时拷贝(copy-on-wite) 页实现，写时拷贝是一种可以推迟甚至免除拷贝数据的技术，内核此时并不复制整个进程地址空间，而是让父进程和子进程共享同一个拷贝。
&emsp;&emsp;只有在需要写入的时候，数据才会被复制，从而使各个进程拥有各自的拷贝。也就是说，资源的复制只有在需要写入的时候才进行，在此之前，只是以只读方式共享。这种技术使地址空间上的页的拷贝被推迟到实际发生写入的时候才进行。在页根本不会被写入的情况下(举例来说，`fork()`后立即调用`exec()`) 它们就无须复制了, `fork()`的实际开销就是复制父进程的页表以及给子进程创建唯一的进程描述符。在一般情况 下，进程创建后都会马上运行一个可执行的文件，这种优化可以避免拷贝大量根本就不会被使用的数据。
**tip:**
&emsp;&emsp;我们目前所谈及的**写时拷贝**，为**数据的写时拷贝**。那么代码会有类似的写时拷贝吗？答案是会的，下文进程替换再向详述。

## `fork()`常规用法
-   一个进程希望复制自己，使子进程同时执行不同的代码段。这在网络服务进程中是常见的——父进程等待委托者的服务请求。当这种请求到达时，父进程调用`fork()`，使子进程处理此请求。父进程则继续等待下一个服务请求。
-   一个进程要执行一个不同的程序。例如子进程从`fork()`返回后，调用`exec()`函数。这对 shell是常见的情况。在这种情况下，子进程在从`fork()`返回后立即调用`exec()`。某些操作系统将这两个操作(`fork()`后调用`exec()`)组合成一个，并称其为spawn。UNIX将这两个操作分开，因为在很多场合需要单独使用`fork()`，其后并不跟随`exec()`。另外，将这两个操作分开，使得子进程在`fork()`和`exec()`之间可以更改自己的属性。例如 I / O重新定向、用户ID、信号排列等。
## `fork()`失败原因
-   系统中有太多的进程(通常意味着某个方面出了问题)。
-   实际用户的进程数超过了限制。其中`CHILD_MAX`规定了每个实际用户ID在任一时刻可具有的最大进程数。
## 补充
很多父进程的**其他性质**也由子进程继承：

```shell
实际用户ID、实际组ID、有效用户ID、有效组ID。
添加组ID。
进程组ID。
对话期ID。
控制终端。
设置-用户- ID标志和设置-组- ID标志。 
当前工作目录。 
根目录。
文件方式创建屏蔽字。
信号屏蔽和排列。
对任一打开文件描述符的在执行时关闭标志。
环境。
连接的共享存储段。
资源限制。
```

**父、子进程之间的区别**：

```shell
fork()的返回值。
进程ID。
不同的父进程ID。
子进程的tms_ utime,tms_stime,tms_cutime以及tms_ustime设置为0。
父进程设置的锁，子进程不继承。
子进程的未决告警被清除。
子进程的未决信号集设置为空集。
```

其中很多特性至今尚末讨论过，并且当调用`fork()`函数后，父子进程：

-   调用一次，返回两次。
-   并发执行。 
-   相同的但是独立的地址空间。 
-   共享文件。 

# 2. 进程终止

&emsp;&emsp;大家有无想过，为何我们的`main()`函数最后会有`return 0;`语句？为何要返回0，其他数字可以吗？这个0又是给谁看呢？其中`return 0;`代表进程退出，0表示进程正常退出，也有其他的进程退出码。不过是给操作系统看的。那么用户如何查看呢？在上一节中我们提到，可以使用`echo $?`查看最近一次执行的程序的退出码。

![image-20221007124806089](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151228506.png)

## 进程退出场景

进程的退出情况无非就三种：

-   代码跑完，结果正确。退出码为0。
-   代码跑完，结果不正确。逻辑问题，程序为崩溃，退出码 !0。
-   代码未跑完（进程崩溃）。此时的退出码无意义。

## 进程退出码

&emsp;&emsp;进程的退出码可以自定义，也可以使用系统的错误码list。当程序运行失败，我们最关心的就是为什么失败？不过计算机并不擅长处理字符串，适合处理整数类型。因此将整数转成错误码描述就是有必要的。在C语言中，我们可以使用`strerror()`查看，需引用头文件`string.h`，示例如下：

```c
#include <string.h>
#include <stdio.h>
int main()
{
    for(int i = 0; i < 140; i++)
    {
        printf("%3d: %s\n", i, strerror(i));
    }
    return 0;
}
```

结果如下：可以看到，有130多个。

![image-20221007131235944](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151228352.png)

但是并不是所有的父进程都关心子进程的退出码，我们所谈及的多为需要关心的情况。
## 进程常见退出方法
有五种方式使进程终止： 
(1) 正常终止： (a) 从`main()`返回。	(b) 调用`exit()`。 	(c) 调用`_exit()`。 
(2) 异常终止： (a) 调用`abort()`。	(b) 由一个信号终止。

### _exit() 和 exit()
`exit()`函数原型如下：
```c
#include <stdlib.h>
void exit(int status);
```
`exit()`函数会导致正常进程终止，`status`&0377的值会返回给父进程。换言之，虽然 status 是int，但是仅有低8位可以被父进程所用。所以`exit(-1)`时，在终端执行`echo $?`发现返回值是255。 

![image-20221007134305730](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151228937.png)

`_exit()`函数原型如下：
```c
#include <unistd.h>
void _exit(int status);
```
`_exit()`函数参数`status`与`exit()`参数一致，范围均为0~255。

**区别**

使用不同头文件的原因是：`exit()`是由ANSIC说明的，而`_exit()`则是由POSIX.说明的。
除此之外，`exit()`最后也会调用*`_exit()`,* 但在调用`_exit()`之前，还做了其他工作：

1.   执行用户通过`atexit()`或`on_exit()`定义的清理函数。按照ANSIC的规定，一个进程可以登记多至32个函数，这些函数将由`exit()`自动调用。我们称这些函数为终止处理程序(exit handler)，并用`atexit()`函数来登记这些函数。

     ```c
     #include <stdlib.h>
     int atexit(void (*function)(void));
     返回: 若成功则为0，若出错则为非0
     ```

     其中，`atexit()`的参数是一个函数地址，当调用此函数时无需向它传送任何参数，也不期望它返回一个值。`exit()`以登记这些函数的相反顺序调用它们。同一函数如若登记多次，则也被调用多次。关于这一点，可以使用下列代码测试：

     使用下列代码测试:

     ```c
     #include <stdlib.h>
     #include <stdio.h>
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
         if(atexit(my_exit1) != 0)
         {
             printf("hanler1 failed\n");
             exit(1);
         }
         if(atexit(my_exit2) != 0)
         {
             printf("hanler2 failed\n");
             exit(2);
         }
         printf("main is done\n");
         return (0);
     }
     ```

     结果如下：

     ![image-20221007145707635](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151228297.png)

     

2.   由于历史原因，`exit()`函数总是执行一个标准 I / O库的清除关闭操作：对于所有打开流调用`fclose()`函数。这造成缓存中的所有数据都被刷新 (写到文件上)。测试如下：

     **`exit()`测试：**

     注：无`\n`，关于这一点，不理解的可以参考前面的文章

     ```c
     #include <stdlib.h>
     #include <stdio.h>
     
     int main()
     {
         printf("nihao");
         exit(1);
     }
     ```

     结果如下：

     ![image-20221007151729005](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151228978.png)

     **`_exit()`测试：**

     ```c
     #include <unistd.h>
     #include <stdio.h>
     
     int main()
     {
         printf("nihao");
         _exit(1);
     }
     ```

     结果如下：

     ![image-20221007152031331](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151228305.png)

3.   调用`_exit()`

     具体关系如下图所示：

![一个C程序是如何起动和终止的](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151229440.png)

### return 返回
&emsp;&emsp;在`main()`函数中，执行 `return n;`等同于执行`exit(n)`，因为调用main的运行时函数会将main的返回值当做`exit()`的参数。

## 如何理解进程终止

站在操作系统的角度，其核心思想：归还资源
-   “释放”曾经为管理进程所维护的所有数据结构对象
-   “释放”程序代码和数据占用的内存空间
-   取消曾经该进程的链接关系
关于上述“**释放**”的解释：
1.   上述"**释放**"表示操作系统并不是直接将资源释放或清空掉，而是设为不用状态，然后保存起来，需要资源再由Slab分配器分配效率就高了。
2.   释放程序代码和数据并非将数据和代码清空，而是将对应的内存设置成无效就可以，后面的程序可以直接覆盖式的使用设置为无效的内存，这样提升释放的效率。
3.   取消链接关系实际上就是对指针指向的操作，进程之间的组织方式是用双链表完成的。
# 3. 进程等待

## 等待必要性

1.   回收僵尸进程，回收资源
2.   获取子进程结束状态
3.   父进程尽量晚于子进程退出，以便规范化资源回收

## 进程等待方法

### `wait()`方法

```c
#include <sys/types.h>
#include <sys/wait.h>
pid_t wait(int *status);
功能:		等待任意子进程。
返回值:	成功返回被等待进程pid,失败返回-1。
参数:		输出型参数,获取子进程退出状态,不关心则可以设置成为NULL
```

使用如下代码测试：

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if(pid < 0)
    {
        perror("fork error\n");
        return 1;
    }
    else if(pid == 0)
    {
        //child
        int count = 3;
        while(count)
        {
            printf("child is running..., count: %d, pid is:%d\n", count--, getpid());
            sleep(1);
        }
        printf("child qiut...\n");
        exit(0);
    }
    else
    {
        //father
        sleep(6);
        printf("father is waiting...\n");
        pid_t ret = wait(NULL);
        sleep(3);
        printf("waiting success, ret is %d\n", ret);
    }

    return 0;
}
```

同时，使用下列代码监控：

```shell
while :; do ps axj | head -1 && ps axj | grep proc | grep -v grep;echo "######################";sleep 1;done
```

结果如下所示：

![image-20221009211012966](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151229098.png)

这时我们看到，当子进程退出后，父进程读取了子进程的退出信息，子进程也就不会变成僵尸进程了。

![image-20221009211214602](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151229622.png)

### `waitpid()`方法

(1) `waitpid()`等待一个特定的进程 (而`wait()`则返回任一终止子进程的状态 )。
(2) `waitpid()`提供了一个`wait()`的非阻塞版本。有时希望取得一个子进程的状态，但不想阻塞。
(3) `waitpid()`支持作业控制。  

函数原型如下：
```c
#include <sys/types.h>
#include <sys/wait.h>
pid_t waitpid(pid_t pid, int *status, int options);
返回值:
    当正常返回的时候waitpid返回收集到的子进程的进程ID；
    如果设置了选项WNOHANG,而调用中waitpid发现没有已退出的子进程可收集,则返回0；
    如果调用中出错,则返回-1,这时errno会被设置成相应的值以指示错误所在；
参数：
pid:
	pid == -1	:等待任一子进程。于是在这一功能方面waitpid与wait等效。
	pid > 0		:等待其进程ID与pid相等的子进程。
	pid == 0	:等待其组ID等于调用进程的组ID的任一子进程。
	pid < -1	:等待其组ID等于pid的绝对值的任一子进程。
status:
    WIFEXITED(status): 若为正常终止子进程返回的状态，则为真。(查看进程是否是正常退出)
    WEXITSTATUS(status): 若WIFEXITED非零，提取子进程退出码。(查看进程的退出码)
options:
	WNOHANG:	若pid指定的子进程没有结束，则waitpid()函数返回0，不予以等待。若正常结束，则返回该子进程的ID。
```

代码验证如下：

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        //child
        int count = 3;
        while(count)
        {
            printf("child is running...pid:%d, ppid:%d, count:%d\n", getpid(), getppid(), count--);
            sleep(1);
        }
        printf("child qiut...\n");
        exit(0);
    }
    sleep(5);
    pid_t ret = waitpid(-1, NULL, 0);
    printf("father wait done... ret:%d, pid:%d\n", ret, getpid());
    sleep(2);
    return 0;
}
```

结果如下：

![image-20221009233325397](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151229646.png)

###  `status`

&emsp;&emsp;`status`：输出型参数，获取子进程的退出状态，不关心可设置为NULL。与`wait()`一致。那我们如何获取子进程的退出码呢？我们将子进程退出码设为45来测试。

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t pid = fork();
    if(pid == 0)
    {
        //child
        int count = 3;
        while(count)
        {
            printf("child is running...pid:%d, ppid:%d, count:%d\n", getpid(), getppid(), count--);
            sleep(1);
        }
        printf("child qiut...\n");
        exit(45);
    }
    sleep(5);
    int status = 0;
    pid_t ret = waitpid(-1, &status, 0);
    printf("father wait done... ret:%d, status:%d, pid:%d\n", ret, status,getpid());
    sleep(2);
    return 0;
}
```

结果如下：

![image-20221009235023033](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151229705.png)

结果差异有点大？这里就得提及一下其结构。`status`不能简单的当作整形来看待，可以当作位图来看待，具体细节如下图（在此只研究status低16比特位）：

![image-20221009235927773](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151229276.png)

基于上图所示，我们将代码稍加修改。

**正常退出**：

```c
int status = 0;
pid_t ret = waitpid(-1, &status, 0);
int code = (status >> 8) & 0xFF;
printf("father wait done... ret:%d, code:%d, pid:%d\n", ret, code, getpid());
sleep(2);
```

结果如下：

![image-20221010000212238](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151229199.png)

那么，我们为何不用全局变量来获取呢？答案显然是不可以的！因为写时拷贝！如果不了解可以参考上一篇文章。

那么父进程又是如何拿到子进程的退出码呢？答案是从子进程的`task_struct`中获取。

**异常退出**：

&emsp;&emsp;如上图所示，当进程异常退出，我们需要获取低7位。我们可以在子进程运行时，发送信号来终止子进程。使用`kill -l`命令来查询。具体关于信号的内容可参看后续文章。

![image-20221010001502433](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151229239.png)

稍加修改上述代码：

```C
int status = 0;
pid_t ret = waitpid(-1, &status, 0);
int code = (status >> 8) & 0xFF;
int sig = status & 0x7F;
printf("father wait done... ret:%d, code:%d, sig:%d, pid:%d\n", ret, code, sig, getpid());
```

正常结果如下：

![image-20221010001955818](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151229305.png)

我们在子进程运行时，通过信号来杀掉子进程，结果如下：

![image-20221010002243841](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151229866.png)

**完整代码逻辑及多进程创建**

&emsp;&emsp;基于上述理解，我们有了完整的进程创建逻辑。不过上述代码均已单个子进程模拟，无法达到真正意义上的多进程。下面来模拟实现一下。同时我们要知道，`fork()`创建子进程后代码共享，如果不处理则会向下图所示。因此，我们需要通过`if`来完成多进程的创建。

![image-20221010074102707](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151230597.png)

并且，我们保存子进程的pid。

```c
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main()
{
    pid_t childs[5];
    for(int i = 0; i < 5; i++)
    {
        pid_t id = fork();
        if(id == 0)
        {
            //child
            printf("child is running...pid is:%d, ppid is:%d\n", getpid(), getppid());
            sleep(2);
            if(i == 4)
            {
                //子进程异常退出
                int *p = 0x11223344;
                *p = 123;
            }
            exit(i);
        }
        childs[i] = id;
    }
    for(int i = 0; i < 5; i++)
    {
        int status = 0;
        pid_t ret = waitpid(childs[i], &status, 0);
        if(ret > 0)
        {
            //等待正常
            int sig = status & 0x7F;
            int code = (status >> 8) & 0xFF;
            if(sig == 0)
            {
                //正常退出
                printf("child:%d qiut normal, exit code:%d\n", childs[i], code);
            }
            else
            {
                printf("child:%d qiut abmormal, sig:%d\n", childs[i], sig);
            }
        }
    }
    return 0;
}
```

结果如下所示：

![image-20221010075623945](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151230111.png)

### 宏

&emsp;&emsp;有三个互斥的宏可用来取得进程终止的原因，它们的名字都以`WIF`开始。基于这三个宏中哪一个值是真，就可选用其他宏来取得终止状态、信号编号等。  

```c
#include <sys/wait.h>
WIFEXITED(status)	:若为正常终止子进程返回的状态，则为真。
    				对于这种情况可执行 WEXITSTATUS(status) 取子进程传送给exit()或_exit()参数的低8位
WIFSIGNALED(status)	:若为异常终止子进程返回的状态，则为真(接到一个不捕捉的信号)。
    				对于这种情况，可执行WIFSIGNALED(status)取使子进程终止的信号编号。
WIFSTOPPED(status)	:若为当前暂停子进程的返回的状态，则为真。
    				对于这种情况，可执行WIFSTOPPED(status)取使子进程暂停的信号编号。
```

对上述代码稍加修改即可：

```c
if(ret > 0)      
{      
    //等待正常      
    if(WIFEXITED(status))       
    {      
        //正常退出      
        printf("child:%d qiut normal, exit code:%d\n", childs[i], WEXITSTATUS(status));      
    }      
    else      
    {      
    	printf("child:%d qiut abmormal, sig:%d\n", childs[i], WIFSIGNALED(status));    
    }
}
```

### `option`

&emsp;&emsp;option参数使我们能进一步控制 `waitpid()`的操作。option参数选择有如下几种：

```c
WNOHANG		:若pid指定的子进程没有结束，则waitpid()函数返回0，不予以等待。若正常结束，则返回该子进程的ID。
WUNTRACED	:若某实现支持作业控制，则由pid指定的任一子进程状态已暂停，且其状态自暂停以来还未报告过，则返回其状态。
    		WIFSTOPPED宏确定返回值是否对应于一个暂停子进程
0			:阻塞式等待
```

&emsp;&emsp;上述示例中，只要子进程未退出，父进程就一直等待子进程退出，并且在等待期间，父进程不能做任何事情，这种等待叫做阻塞等待。实际上我们可以让父进程不要阻塞等待，即子进程未退出时父进程执行自己的代码，当子进程退出时再读取子进程的退出信息，即非阻塞等待。
&emsp;&emsp;阻塞本质就是：调用该函数的父进程由在运行队列被放入到了等待队列中等待，同时修改进程状态为S。
&emsp;&emsp;`waitpid()`返回的本质也就是：将该父进程从等待队列拿到运行队列中执行，同时修改进程状态为R。

因此，基于非阻塞接口的轮询检测方案示例如下：

```c
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
```

结果如下：

![image-20221010132330949](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151230700.png)

# 4. 进程程序替换

## 为什么&&是什么

创建子进程的目的：

1.   执行父进程的部分代码。因为父子进程共享代码，我们通常通过if 分流。
2.   执行其他程序的代码。

我们曾说过，创建子进程时代码也是可以写时拷贝的，并提及用`fork()`函数创建子进程后，子进程往往要调用一种`exec()`函数以执行另一个程序。 简而言之就是让进程不再执行原进程的代码和数据，而是执行新的代码和数据。

前面的文章我们曾提及，shell下运行的指令，通过创建子进程并在`PATH`中保存的指令的搜索路径下来运行。那么为何创建的子进程没有执行父进程的代码呢？

## 替换原理

当进程调用一种`exec()`函数时，该进程的用户空间代码和数据完全被新程序替换完全由新程序代换，而新程序则从其`main()`函数开始执行。 因为调用`exec()`并不创建新进程，所以前后的进程 ID并未改变。 `exec()`只是用另一个新程序替换了当前进程的正文、数据、堆和栈段。

![image-20221010180116777](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151230749.png)

那么，系统在进程替换时有无创建新的进程呢？并没有。该进程对应的PCB、进程地址空间以及页表等数据结构均为发生改变，只是进程在物理内存当中的数据和代码发生了改变，且进程的pid并没有改变。除此之外，执行新程序的进程还保持了原进程的下列特征：

```c
进程ID和父进程ID。
实际用户ID和实际组ID。
添加组ID。
进程组ID。
对话期ID。
控制终端。
闹钟尚余留的时间。
当前工作目录。
根目录。
文件方式创建屏蔽字。
文件锁。
进程信号屏蔽。
未决信号。
资源限制。
tms_utime, tms_stime, tms_cutime以及tms_ustime值。  
```

## 替换函数

```c
#include <unistd.h>
int execl(const char *path, const char *arg, ...);
int execv(const char *path, char *const argv[]);
int execlp(const char *file, const char *arg, ...);
int execvp(const char *file, char *const argv[]);
int execle(const char *path, const char *arg, ...,char *const envp[]);
int execve(const char *path, char *const argv[], char *const envp[]);
```

**`int execl(const char *path, const char *arg, ...)`**

第一个参数是要执行程序（可能要带路径），第二个参数是可变参数列表，表示你要如何执行这个程序，并以`NULL`结尾。

例如：

```C
execl("/usr/bin/ls", "ls", "-l", "-i", NULL);
```

结果如下：

![image-20221011200819516](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151230685.png)

**`int execv(const char *path, char *const argv[])`**

示例：

```c
char *const myargv[] = {"ls", "-a", "-l", "-i", NULL};                                                   execv("/usr/bin/ls", myargv);
```

**`int execlp(const char *file, const char *arg, ...)`**

带p的，可以使用环境变量`PATH`，无需写全路径 。示例：

```c
execlP("ls", "ls", "-l", "-i", NULL);
```

**`int execvp(const char *file, char *const argv[])`**

示例：

```c
execvp("ls", myargv);
```

**`int execle(const char *path, const char *arg, ...,char *const envp[])`**

e表示环境变量，我们可以使用`getenv()`来获取环境变量，使用下列代码：

```c
#include <stdio.h>
#include <stdlib.h>

int main()
{
    for(int i = 0; i < 3; i++)
    {
        printf("commad:%d\n", i);
    }
    printf("getenv:%s\n", getenv("VALUE"));
    return 0;
}
```

结果如下：

![image-20221011204216436](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151230245.png)

然后，我们在源程序中使用如下代码测试：

```c
char *const myenv[] = {"VALUE=nihao", NULL};    
exele("./mycmd", "mycmd", NULL, myenv);
```

结果如下：

![image-20221011210103303](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151230704.png)

**`int execve(const char *path, char *const argv[], char *const envp[])`**

示例：

```c
char *const argv[] = {"mycmd", NULL};    
char *const myenv[] = {"VALUE=nihao", NULL};    
execve("./mycmd", argv, myenv);
```

事实上，系统中还有一个函数：

```c
int execvpe(const char *file, char *const argv[], char *const envp[]);
```

示例：

```c
char *const argv[] = {"mycmd", NULL};    
char *const myenv[] = {"VALUE=nihao", NULL};    
execvpe("mycmd", argv, myenv);
```

事实上，上述代码并不能按预期运行。即便当前待替换的进程处于当前路径下，仍需将当前路径保存到`PATH`中才可以。

## 函数解释

-   这些函数如果调用成功则加载新的程序从启动代码开始执行,不再返回。

-   如果调用出错则返回-1

-   所以`exec*()`函数只有出错的返回值而没有成功的返回值。  

-   被替换的进程的退出码无意义。

-   上述函数只有一个`execve()`是内核的系统调用。另外五个只是库函数，它们最终都要调用系统调用。这六个函数之间的关系示于下图。

    ![image-20221012002239309](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151230767.png)

## 命名理解

上述函数看起来难记，其实掌握命名规律便很好理解。

-   l(list) : 表示参数采用列表
-   v(vector) : 参数用数组
-   p(path) : 有p自动搜索环境变量PATH
-   e(env) : 表示自己维护环境变量  

## mini shell实现

**执行逻辑**

-   ① `fork()`创建子进程，让子进程进行命令行解释；
-   ② 子进程出现任何问题，都不影响父进程Shell，进程间具有相对独立性；
-   ③ 我们所使用的shell在执行完命令行后一直不会退出，本质上就是一直在`fork()`子进程，然后让子进程代替父进程执行**部分命令**，父进程等待子进程退出 (防止子进程变为僵尸进程)，循环执行以上操作，在一定程度上保证了shell 的安全。

**前置知识**
**获取主机名**
```c
#include <unistd.h>
int gethostname(char *name, size_t len);
功能：返回本地主机的标准主机名
```
**获取用户信息**
```c
#include <sys/types.h>
#include <pwd.h>
struct passwd *getpwuid(uid_t);
功能：用来搜索用户uid, 找到时便将该用户的数据以结构passwd结构返回。
struct passwd *getpwnam(const char *name);
功能：获取用户登录相关信息。
```
`struct passwd`该结构体的常用有:
```c
struct passwd {
    char   *pw_name;       /* username */
    char   *pw_passwd;     /* user password */
    uid_t   pw_uid;        /* user ID */
    gid_t   pw_gid;        /* group ID */
    char   *pw_gecos;      /* user information */
    char   *pw_dir;        /* home directory */
    char   *pw_shell;      /* shell program */
};
```

**获取当前路径**

```c
#include <unistd.h>
char *getcwd(char *buf, size_t size);
buf		:getcwd()将内含当前工作目录绝对路径的字符串存放在 buf 缓冲区中。
size	:缓冲区的大小，分配的缓冲区大小必须要大于字符串长度，否则调用将会失败。
返回值	  :如果调用成功将返回指向 buf 的指针，失败将返回 NULL，并设置 errno。
```

**切换路径**

```c
#include <unistd.h>
int chdir(const char *path);
path	:将进程的当前工作目录更改为path参数指定的目录,可以是绝对路径、也可以是相对路径,指定的目录必须要存在,否则会报错。
返回值	:成功返回0;失败均返回-1;并设置 errno。
```

&emsp;&emsp;有了上述补充，我们可以很好的实现自己的命令行解释器：在这里，我们将主机名更改为`myhost`以便区分：

```c
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
	if(i > 0)
    {
        strcpy(path, path + i + 1);
    }
    else if(i < 0)
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
        struct passwd* ps = getpwuid(getuid());
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
```

**关于`cd`的解释说明：**

将`cd`指令交给子进程执行，与此同时父进程打印子进程退出码，出现下列结果：

![image-20221015110729377](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151230211.png)
其他命令成功执行则退出码返回0，失败返回1。可以看到，`cd`命令也是成功执行的，可为什么所处路径仍未改变呢？
我们可以使用`ls /proc`查看已有进程。在其目录下存在`cwd`文件，该文件保存着该进程当前所处路径。

![image-20221015111235458](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/202210151230694.png)

可以看到，我们得`minishell`路径并未改变，但其`cd`命令又是成功执行了的。事实上，我们所改变的是子进程的路径，而我们所想要的是改变父进程`minishell`的路径，在这里我们可以将`cd`命令交予父进程执行，因此我们使用`chdir()`函数来执行。基于此，我们可以很好的执行大部分命令，如下所示：

![shell](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux6/minishell.gif)

------
&emsp;&emsp;以上就是本次关于进程控制的简单总结，欢迎各位批评指正！
