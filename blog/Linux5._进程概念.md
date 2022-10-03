[TOC]

------

# 1. 基本概念

**经典定义：**

>   • 一个正在执行中的程序。
>   • 一个正在计算机上执行的程序实例。
>   • 能分配给处理器并由处理器执行的实体。
>   • 一个具有以下特征的活动单元:一组指令序列的执行、—个当前状态和相关的系统资源集合。

**内核观点：**担当分配系统资源（CPU时间，内存）的实体。 

**进程与程序 — process VS program :**

&emsp;&emsp;程序一般是放置在实体磁盘中，然后通过使用者的执行来触发。触发后会载入到内存（参考**冯•诺依曼体系结构**）中成为一个个体，那就是进程。 为了操作系统可管理这个进程，因此进程有给予执行者的权限/属性等参数，并包括进程所需要的指令码与数据或文件数据等，最后再给予一个PID。系统就是通过这个PID来判断该process是否具有权限进行工作的！ 
![程序被载入成为程序以及相关数据
的示意图  ](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615076.png)

# 2. 描述进程-PCB 

&emsp;&emsp;从上述表达中我们知道，进程被触发后，执行者的权限与属性、进程的指令码与所需数据等都会被载入内存中。如下图所示，一台机器同时运行上百个进程，那就必须管理好这些进程及数据。

![image-20220920154139582](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615077.png)

&emsp;&emsp;那计算机是如何管理的呢？简而言之：**先描述，再组织**。当一个进程出现时，操作系统就立马对其进行描述。进而操作系统对进程的管理转化成为对进程信息的管理。进程信息被放在一个叫做进程控制块的数据结构中，可以理解为进程属性的集合。 教材定义为：PCB（process control block），Linux操作系统下的PCB是: **task_struct** 。
&emsp;&emsp;操作系统对每一个进程都进行描述，形成了一个个的进程控制块（PCB），并将这些PCB以双链表的形式组织起来。**进而对进程管理，转化为对双链表的增删查改！**

![进程管理—双链表的增删查改](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615078.png)

&emsp;&emsp;进程 = 程序 + 内核申请的数据结构（PCB)。

**task_struct**

&emsp;&emsp;task_struct是 **PCB** 的一种，同时 Linux 操作系统又是由C语言编写。故其具有以下特征。

>   1.   是Linux中描述进程的结构体。
>   2.   Linux内核的一种数据结构，它会被装载到RAM(内存)里并且包含着进程的信息。

**task_ struct内容分类  **

&emsp;&emsp;在进程执行时，任意给定一个时间，进程都可以惟一地被表征为 以下元素：

>   **标示符**: 				描述本进程的唯一标示符，用来区别其他进程。
>   **状态**: 					任务状态，退出代码，退出信号等。
>   **优先级**: 				相对于其他进程的优先级。
>   **程序计数器**: 		程序中即将被执行的下一条指令的地址。
>   **内存指针**: 			包括程序代码和进程相关数据的指针，还有和其他进程共享的内存块的指针
>   **上下文数据**:		  进程执行时处理器的寄存器中的数据。
>   **I/O状态信息**:		包括显示的I/O请求,分配给进程的I／ O设备和被进程使用的文件列表。
>   **记账信息**: 			 可能包括处理器时间总和，使用的时钟数总和，时间限制，记账号等。
>   其他信息 

# 3. 查看进程

&emsp;&emsp;既然进程这么重要，那么我们如何查阅系统上面正在运行当中的进程呢？很简单啊！ 利用静态的 ps 或者是动态的 top，还能以 pstree 来查阅进程树之间的关系喔！

## 3.1 PS 命令

**ps ：将某个时间点的程序运行情况撷取下来  **

```shell
常用选项与参数：
-A		:所有的process均显示出来，与-e具有同样的效用;
-a		:不与terminal有关的所有process;
-u		:有效使用者(effective user)相关的process;
x		:通常与a这个参数一起使用，可列出较完整信息。
输出格式规划：
l		:较长、较详细的将该PID的信息列出;
-j		:工作的格式(jobs format);
-f		:做一个更为完整的输出。
```

&emsp;&emsp;个人认为ps这个指令的man page不是很好查阅，写的非常的庞大！因此建议你直接背几个常用选项。 其中，单独使用 ps 命令，会显示所有进程信息。

常用方式：

```shell
ps aux	:查看正在运行进程信息（主要查 pid）。
ps ajx	:更加详细（PPID:父进程、PID、PGID:进程组 id、 SID:会话等）。
ps aux | grep 关键字	:一般过滤使用
```

![ps aux](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615079.png)

![ps ajx](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615080.png)

搭配 **grep** 工具使用如下：

![image-20220920171706197](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615081.png)

**参数说明**

```shell
USER	:该process属于那个使用者帐号的？
PID		:该process的程序识别码。
%CPU	:该process使用掉的CPU资源百分比；
%MEM	:该process所占用的实体内存百分比；
VSZ		:该process使用掉的虚拟内存量(KBytes)
RSS		:该process占用的固定的内存量(KBytes)
TTY		:该process是在那个终端机上面运行，若与终端机无关则显示	?，另外，tty1-tty6是本机上面的登陆者程序，若为pts/0等等的，则表示为由网络连接进主机的程序。
STAT	:该程序目前的状态，状态显示与	ps-l的S旗标相同(R/S/T/Z)
START	:该process被触发启动的时间；
TIME	:该process实际使用CPU运行的时间。
COMMAND	:该程序的实际指令
PGID	:Process Group ID 进程组ID
TGID	:Thread Group ID线程组ID
SID		:Session ID 回话ID
```

## 3.2 通过proc

在根目录下，存在名为一个proc的目录，

![image-20220920195057939](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615082.png)

在根目录下，存在许多数字名的文件。

![image-20220920195233542](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615083.png)

这些数字其实是某一进程的PID，对应文件夹当中记录着对应进程的各种信息。我们若想查看PID为1的进程的进程信息，则查看名字为1的文件夹即可。

![image-20220920200012069](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615084.png)

## 3.3 top：动态观察程序的变化

**top**: 显示系统各个进程的资源占用情况。

![image-20220920200743030](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615085.png)

**第一行：任务队列信息**

```
系统当前时间：top - 20:08:48
系统运行时间：up 12 days, 23:21
当前登录用户：2 user
负载均衡情况：load average: 0.03，0.02，0.05（average后面的三个数分别是1分钟、5分钟、15分钟的负载情况。）
```

![image-20220920200908484](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615087.png)

**第二行：Tasks — 进程**

```
总进程：	103 total
运行进程：	2 running
休眠进程：	100 sleeping
停止进程：	0 stopped
僵尸进程：	1 zombie
```

![image-20220920201203121](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615088.png)

**第三行：cpu状态信息**

```shell
0.7 us：	用户空间占用CPU的百分比。
0.3 sy：	内核空间占用CPU的百分比。
0.0 ni：	改变过优先级的进程占用CPU的百分比
99.0 id：空闲CPU百分比
0.0 wa：	IO等待占用CPU的百分比
0.0 hi：	硬中断占用CPU的百分比
0.0 si：	软中断占用CPU的百分比
0.0 st：	当Linux系统是在虚拟机中运行时，等待CPU资源的时间占比
```

![image-20220920201326452](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615089.png)

**第四行：内存状态**

KiB Mem：Kib表示描述单位，MEM表示内存

```shell
total：		总内存量
free：		空闲内存
used：		已用内存
buff/cache：	缓存内存
```

![image-20220920201538107](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615090.png)

**第五行：swap交换分区信息**

KiB Swap：Kib表示描述单位，Swap表示交换分区

```shell
total：		总内存量
free：		空闲内存
used：		已用内存
avail Mem：	可用内存
```

![image-20220920201827420](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615091.png)

**第六行：各进程状态监控**

```shell
PID		:进程id
USER	:进程所有者
PR		:Priority的简写，程序的优先执行顺序，越小越早被执行
NI		:nice值。负值表示高优先级，正值表示低优先级
VIRT	:进程使用的虚拟内存总量，单位kb。VIRT=SWAP+RES
RES		:进程使用的、未被换出的物理内存大小，单位kb。RES=CODE+DATA
SHR		:共享内存大小，单位kb
S		:进程状态。D=不可中断的睡眠状态；R=运行；S=睡眠；T=跟踪/停止；Z=僵尸进程
%CPU	:上次更新到现在的CPU时间占用百分比
%MEM	:进程使用的物理内存百分比
TIME+	:进程使用的CPU时间总计
COMMAND	:进程名称（命令名/命令行）
```

![image-20220920201958647](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615092.png)

**常用命令**

```shell
top [参数]
```

**常用参数**

```shell
-c 			显示完整的命令路径
-d <时间> 	设置间隔时间
-u <用户名> 	指定用户名
-p <进程号> 	指定进程
-n <次数> 	循环显示的次数
```

-p

![image-20220920202647995](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615093.png)

-u

![image-20220920202726864](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615094.png)

## 3.4 pstree

**语法**

```shell
pstree	[参数]
```

**参数**

```shell
-A		:各程序树之间的连接以	ASCII字符来连接；
-U		:各程序树之间的连接以万国码的字符来连接。在某些终端接口下可能会有错误；
-p		:并同时列出每个process的PID；
-u		:并同时列出每个process的所属帐号名称。
```

**意义**

这个pstree可以查询程序之间的相关性，还会使用线段将相关性程序链接起来！ 一般链接符号可以使用ASCII 码即可，有时会以Unicode符号来链接， 若终端机无法支持该编码，或许会造成乱码问题。可以加上-A选项来克服此类线段乱码问题。

# 4. 进程标识符

&emsp;&emsp;每个进程在系统中都有唯一的一个ID标识它，这个ID就是进程标识符(PID)。因为其唯一性，所以系统可以根据它准确定位到一个进程。进程标识符的类型为pid_t，其本质上是一个无符号整型的类型别名(typedef)。每个进程都有6个重要的ID值，分别是：**进程ID、父进程ID、有效用户ID、有效组ID、实际用户ID和实际组ID**。除了进程ID和父进程ID这两个值不能够更改以外，其他的4个ID值在适当的条件下可以被更改。

```c++
#include <unistd.h>
#include <sys/types.h>
pid_t getpid(void);    	//获取进程ID
pid_t getppid(void); 	//获取父进程ID
uid_t getuid(void);    	//获取用户ID
uid_t geteuid(void);    //获取有效用户ID
gid_t getgid(void);    	//获取组ID
gid_t getegid(void);    //获取有效组ID
```

**子进程与父进程：** 

&emsp;&emsp;在上文pstree中我们提及，程序彼此之间是有相关性的。
&emsp;&emsp;比如：当我们登陆系统后，会取得一个 bash 的 shell ，然后，我们用这个 bash 提供的接口去执行另一 个指令，例如 ./test ，那些另外执行的指令也会被触发成为 PID。那个后来执行指令才产生的 PID 就是“子进程”了，而在我们原本的 bash 环境下，就称为“父进程”了！

参考代码：

```c++
#include <iostream>    
#include <unistd.h>    
#include <sys/types.h>    
    
using namespace std;    
    
int main()    
{                                          
        cout << "this process pid is:    " << getpid() << endl;
        cout << "ppid is:                " << getppid() << endl;            
        cout << "uid is:                 " << getuid() << endl;
        cout << "euid is:                " << geteuid() << endl;   
        cout << "gid is:                 " << getgid() << endl;     
        cout << "egid is:                " << getegid() << endl;   
        while(true){                                                    
            sleep(1);                                                      
        }                                                                
    	return 0;                                                 
}  
```

结果如下图所示：

![image-20220920224455356](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615095.png)

# 5. 创建进程-fork初识

## fork函数创建子进程

在Linux中，使用 fork()函数创建子进程。

```shell
#include <unistd.h>
#include <sys/types.h>
pid_t fork(void);
```

**示例**

```c++
#include <iostream>    
#include <unistd.h>    
#include <sys/types.h>    
    
using namespace std;    
    
int main()    
{    
    fork();    
    while(true)    
    {    
        cout << "i am a process, pid is: " << getpid() << " ,ppid is: " << getppid() << endl;    
        sleep(1);    
    }                                   
    return 0;    
} 
```

结果如下

![image-20220921231836314](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615096.png)

可以看到，两个进程都不断循环打印。可以看出，创建出来的进程是原进程的子进程。

**理解**

那么。我们该如何理解创建出来的子进程呢？由上图可以看到，新创建的进程指令也是 ./test。

1.   站在程序员的角度来看

     父子进程共享用户代码，但数据各自私有一份。怎么理解这句话呢？只要是用户代码，那就是只可读不可修改的。那数据各自私有一份呢？举个例子，当我们杀掉QQ进程时候，并不会影响微信等其它进程。也就是所，操作系统中，所有进程之间具有独立性，不让进程间互相干扰。那么，子进程又是如何做到数据私有？这里简单说一下：写时拷贝。

2.   站在内核角度

     系统多了一个进程，那就必须创建相关的PCB，在Linux中就是多了一个task_struct，而创建子进程，默认以父进程为模板，使用的是父进程的代码和数据（写时拷贝）。

**tips:**

使用 fork() 函数创建子进程后，这两个进程被操作系统调度的顺序是不确定的，这取决于操作系统调度算法的具体实现。并不意味着父进程一定先于子进程执行。

## fork()返回值

fork()返回值如下：

```
0	:子进程中，返回0
pid	:父进程中，返回的是子进程的pid
-1	:出错返回
```

如何理解上述意思呢？来段代码：

```C++
#include <iostream>    
#include <unistd.h>    
#include <sys/types.h>    
    
using namespace std;    
    
int main()    
{    
   	pid_t ret = fork();
    if(ret == 0)
    {
        //子进程
        while(true)
        {
            cout << "i am child,pid is: " << getpid() << ",ppid is: " << getppid() << endl;
            sleep(1);
        }
    }
    else if(ret > 0)
    {
        //父进程
        while(true)
        {
            cout << "i am father, pid is: " << getpid() << ",ppid is: "<< getppid() << endl;
            sleep(1);
        }
    }
    else{
        cerr << "fork failed " << endl;          
    }                                
    return 0;    
} 
```

你认为结果如何呢？是执行哪一个死循环还是同时执行双死循环呢？结果如下：

![image-20220922001501186](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615097.png)

是否觉得不可思议？怎么会同时执行两个死循环？也就是说，fork()有两个返回值？上文我们提及，父子进程代码共享，当fork()执行其return 语句时，其子进程必然已经创建完成，既然创建完成，那么return 语句执行两次也就可以理解了。具体内容需要了解地址空间等内容才可以掌握。可以参考后续文章。

有了上述简单了解，我们再来看看，既然父子进程工作内容一样，何必创建两个进程呢？既然父进程和子进程获取到fork()函数的返回值不同，那我们就可以据此来让父子进程执行不同的代码，从而做不同的事。通常，我们使用 **if 语句**进行分流。代码如上。

# 6. 进程状态

操作系统基本职责控制进程的执行，在任何时刻进程分为正在执行和未执行两种状态，因而构建出下列两状态进程模型。



![两状态模型图](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615098.png)

不过，若所有进程都做好了执行准备，则上述模型b的排队原则是有效的。对于可运行的进程，处理器以**轮循**方式操作（依次给队列中的进程一定的执行时间，然后返回队列，阻塞情况除外）。但是：面对一些处于非运行态但是处于就绪等待执行的进程，但同时存在处于阻塞态等待I/O 结束的进程的情况来说，选择队列处理最久的进程这一方式显然不可以，而应该扫描整个列表未阻塞且在队列最久的进程。为解决这一情况，将非运行态分为两个状态：就绪和阻塞。此外还新增了两个状态，如下图所示：



![五状态进程模型](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615099.png)



不过上述只是操作系统描述的状态，也就是说放到任一操作系统下都可以说得过去，但是要真正理解，必须具体到某一操作系统。
这里我们具体谈论Linux中的进程状态，Linux操作系统的源代码当中对于进程状态（在 Linux内核里，进程有时候也叫做任务）有如下定义，下面的状态在kernel源代码里定义：

```c
/*
* The task state array is a strange "bitmap" of
* reasons to sleep. Thus "running" is zero, and
* you can test for combinations of others with
* simple bit tests.
*/
static const char * const task_state_array[] = {
"R (running)", 		/* 0 */
"S (sleeping)", 	/* 1 */
"D (disk sleep)", 	/* 2 */
"T (stopped)", 		/* 4 */
"t (tracing stop)", /* 8 */
"X (dead)", 		/* 16 */
"Z (zombie)",		/* 32 */
};
```

![image-20220922141434063](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615100.png)

## 进程状态查看

在**查看进程**一节中，我们介绍了**ps、top** 等命令，可以用来查看进程状态。

**补充：**

```shell
ps -l
```

![ps -l](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615101.png)

其中，参数含义如下：

```shell
F				:代表这个程序旗标(process flags)，说明这个程序的总结权限,常见号码有:
					若为4表示此程序的权限为root;
					若为1则表示此子程序仅进行复制(fork)而没有实际执行(exec)
S				:代表这个程序的状态(STAT)
UID/PID/PPID	:代表“此程序被该UID所拥有/程序的PID号码/此程序的父进程PID"号码”
C				:代表CPU使用率，单位为百分比;
PRI/NI			:Priority/Nice的缩写，代表此程序被CPU所执行的优先顺序，数值越小代表该程序越快被CPU执行。
ADDR/SZ/WCHAN	:都与内存有关，ADDR是kernel function，指出该程序在内存的哪个部分，如果是个running的程序，一般就会显示“-”/SZ表此程序用掉多少内存/WCHAN表示目前程序是否运行中，同样的， 若为-表示正在运行中。
TTY				:登陆者的终端机位置，若为远端登陆则使用动态终端接口(pts/n);
TIME			:使用掉的CPU时间，注意，是此程序实际花费CPU运行的时间，而不是系统时间;
CMD				:就是command的缩写，造成此程序的触发程序之指令为何
```

## R状态

如果一个状态处于R状态(running)，那么他一定是在CPU上面运行的吗？我们将上述代码运行起来，结果如下：

![image-20220922144724992](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615102.png)

可以发现多个进程同时处于R状态。但是我们的CPU是单核的，绝不会一直只运行某一个进程。因此，R状态表示：进程处于运行队列中，即为R状态，意味着我准备好了，可以被调度。

## S状态

S睡眠状态(sleeping)：意味着进程在等待事件完成。这里的睡眠有时候也叫做可中断睡眠（interruptible sleep) 或浅度睡眠。  表示可以对外部事件作出反应。

再次调用上述代码：

```c++
#include <iostream>    
#include <unistd.h>    
#include <sys/types.h>    
    
using namespace std;    
    
int main()    
{    
   	pid_t ret = fork();
    if(ret == 0)
    {
        //子进程
        while(true)
        {
            cout << "i am child,pid is: " << getpid() << ",ppid is: " << getppid() << endl;
            sleep(1);
        }
    }
    else if(ret > 0)
    {
        //父进程
        while(true)
        {
            cout << "i am father, pid is: " << getpid() << ",ppid is: "<< getppid() << endl;
            sleep(1);
        }
    }
    else{
        cerr << "fork failed " << endl;          
    }                                
    return 0;    
} 
```

其中状态如下：

![image-20220922145748184](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615103.png)

可以看到，此时父子进程均处于S状态。按下 [Ctrl] + [c]，既可以终止该进程。

![image-20220922150122510](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615104.png)

## D状态

D磁盘休眠状态(Disk sleep)有时候也叫不可中断睡眠状态(uninterruptible sleep)，在这个状态的进程通常会等待IO的结束，不可以被杀掉，即便是操作系统。只能等待进程自动唤醒或者重启。

举个例子：

运行一个进程，让该进程向磁盘中读取数据。我们知道，系统I/O时间是比较长的，当时间片到了，I/O仍未结束，那么此时进程就不应该被杀掉。

## T状态

T停止状态（stopped）：可以通过发送 SIGSTOP 信号给进程来停止（T）进程。这个被暂停的进程可以通过发送 SIGCONT 信号让进程继续运行。 
在Linux当中，我们使用 kill -19就可以使指定进程停止。

![image-20220922205733519](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615105.png)

使用 kill -18就可以使指定进程继续运行。

![image-20220922205933581](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615106.png)

## Z状态

僵死状态（Zombies）是一个比较特殊的状态，当进程退出时，会将自己退出时的相关信息自动写入到进程的PCB中，供OS或者父进程读取。读取成功后，该进程才算真正死亡。僵死进程会以终止状态保持在进程表中，并且会一直在等待父进程读取退出状态代码。所以，只要子进程退出，父进程还在运行，但父进程没有读取子进程状态，子进程进入Z状态。以下列代码为例：

```c++
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
```

可以看到：当父进程一直不读取，子进程就是Z状态。

![image-20220922215023047](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615107.png)

**必要性**

那么：为什么要存在僵尸进程呢？

僵尸进程中保存着很多对程序员和系统管理员非常重要的信息，首先，这个进程是怎么死亡的？是正常退出呢，还是出现了错误，还是被其它进程强迫退出的？其次，这个进程占用的总系统CPU时间和总用户 CPU时间分别是多少？发生页错误的数目和收到信号的数目。这些信息都被存储在僵尸进程中，试想如果没有僵尸进程，进程一退出，所有与之相关的信息都立刻归于无形。

**危害**

>   僵尸进程的退出状态必须一直维持下去，因为它要告诉其父进程相应的退出信息。可是父进程一直不读取，那么子进程也就一直处于僵尸状态。
>   僵尸进程的退出信息被保存在task_struct(PCB)中，僵尸状态一直不退出，那么PCB就一直需要进行维护。
>   若是一个父进程创建了很多子进程，但都不进行回收，那么就会造成资源浪费，因为数据结构对象本身就要占用内存。
>   僵尸进程申请的资源无法进行回收，那么僵尸进程越多，实际可用的资源就越少，也就是说，僵尸进程会导致内存泄漏。

**补充**

在linux中进程退出之后会有一个退出状态，可以通过echo $?进行查看。而且，这个退出码是由刚刚执行完的进程提供给系统内核的。

![echo $?$](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615108.png)

那么不同的退查状态又说明进程发生了什么了呢？可以通过perror进行查看！

![perror](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615109.png)

## X状态

X死亡状态(dead)：这个状态只是一个返回状态，当一个进程的退出信息被读取后，其PCB（task_struct)等申请的资源就会被立即释放，所以你也无法看到这一状态。

## 孤儿进程

假如父进程先于子进程退出，那么子进程如何呢？父进程先退出，子进程就称之为“孤儿进程”，孤儿进程被1号进程领养，当然要由1号进程回收喽。  

```c++
#include <iostream>    
#include <unistd.h>    
#include <stdlib.h>    
                                          
using namespace std;                      
                                          
int main()                                
{                                         
    if(fork() == 0)                       
    {                                                                                       
        cout << "i am child,pid is: " << getpid() << " ,ppid is: " << getppid() << endl;    
        sleep(10);    
        cout << "i am child,pid is: " << getpid() << " ,ppid is: " << getppid() << endl; 
        exit(1);          
    }                                                                                                   
    cout << "i am father,pid is: " << getpid() << " ,ppid is: " << getppid() << endl;
    sleep(5);
    return 0; 
}  
```

使用下列命令来动态查询进程状态。

```shell
[xcs101@VM-4-6-centos process]$ while : ; do ps axj | head -1 && ps axj | grep 'orphan'; sleep 1; echo "##########################" ; done;
```

结果如下：

![image-20220923000635217](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615110.png)

其中，1号进程信息如下：

![image-20220923001448181](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615111.png)

**补充**

有时候咱们看到的不是R/S等状态，而是多了一个 ’+‘ 号。这表示是前台进程。在命令后面加上一个 & 符号，表示该命令放在后台执行。如下图：

![image-20220922234543532](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615112.png)

结束后台进程，可以用kill pid 来结束。其中，**Z/D状态进程，无法被kill -9 杀掉。**

# 7. 进程优先级

进程cpu资源分配就是指进程的优先权（priority）。优先权高的进程有优先执行权利。

## 优先级VS权限

那么，优先级和权限区别在哪呢？权限（privilege）是指特定的用户具有特定的系统资源使用权力，像是文件夹，特定系统指令的使用或存储量的限制。权限是有或没有的问题，而优先级则是在已经具有了权限而讨论权限大小的问题。
简而言之：
优先级： 一定能得到某种资源，不过是先后顺序问题；
权限： 	决定你能否得到某种资源。

## 优先级存在原因

为什么要有优先级，其本质就是资源的有限。存在进程优先级的主要原因就是CPU资源是有限的，一个CPU一次只能跑一个进程，而进程是有很多，所以需要存在进程优先级，来确定进程获取CPU资源的先后顺序。

## 查看进程优先级

前文提及到下列两个命令，这两个命令各参数含义也已介绍过了。

```shell
ps -l
top 
```

其中，Linux的优先级由PRI和NI值共同决定，数值越小，优先级越高。但也不可能一味的低或高，避免饥饿问题。nice值就是优先级的修正数据，其范围[-20, 19]。

![image-20220923151227898](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615113.png)

```shell
UID	:在Linux系统中，标识用户并非按照用户名来标识的，而是通过用户的UID
PRI :代表这个进程可被执行的优先级，其值越小越早被执行
NI 	:代表这个进程的nice值  
```

## 调整进程的nice

1.   **top**

​	进入top后按 “r” –>输入进程PID–>输入nice值。其中，若nice为负值，需要提升权限（sudo）执行。

![image-20220923174602680](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615114.png)

2.   **renice**

```shell
renice [nice值] 进程PID
```

![image-20220923175350812](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615115.png)

若降低nice值，也需提升权限（sudo）。

## PRI && NI

-   **PRI**	:即进程的优先级，或者通俗点说就是程序被CPU执行的先后顺序，此值越小进程的优先级别越高;
-   **NI**	  :就是我们所要说的nice值了，其表示进程可被执行的优先级的修正数值；
-   PRI值越小越快被执行，那么加入nice值后，将会使得PRI变为PRI(new)=PRI(old)+nice；

那么，如何理解PRI(new)=PRI(old)+nice呢？看下图我们发现，原先nice值已经为13，pri为93，当修改nice值为15后，pri并没有按照93 + 15 = 108，而是80 + 15 = 95。无论如何修改，我们发现，pri(old)都是80，这是一个默认值。

1.   同时也是一个基准值。方便调整，实现简单。
2.   避免用户绕过系统限制，通过多次调整nice值跳过nice值范围限定，过度调整pri。

![image-20220923175350812](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615115.png)

-   调整进程优先级，在Linux下，就是调整进程nice值；

-   nice其取值范围是-20至19，一共40个级别。

该范围是一个可控范围。OS的调度原则，是公平高效的调度，而不是平均。范围过大并不合适。并且，超出nice范围的修改，默认是以最大范围修改。

![image-20220923191640822](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615116.png)

## 其他概念

-   **竞争性**: 系统进程数目众多，而CPU资源只有少量，甚至1个，所以进程之间是具有竞争属性的。为了高效完成任务，更合理竞争相关资源，便具有了优先级
-   **独立性**: 多进程运行，需要独享各种资源，多进程运行期间互不干扰
-   **并行**: 多个进程在多个CPU下分别，同时进行运行，这称之为并行
-   **并发**: 多个进程在一个CPU下采用进程切换的方式，在一段时间之内，让多个进程都得以推进，称之为并发  

# 8. 环境变量

## 基本概念

环境变量(environment variables)：一般是指在操作系统中用来指定操作系统运行环境的一些参数。

>   我们在编写C/C++代码的时候，在链接的时候，从来不知道我们的所链接的动态静态库在哪里，但是照样可以链接成功，生成可执行程序，原因就是有相关环境变量帮助编译器进行查找。  

环境变量通常具有某些特殊用途，还有在系统当中通常具有全局特性。在Windows中也是可以查看的。

![image-20220923215942374](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615118.png)



## 查询环境变量

1.   **echo**

     语法如下：

     ```shell
     echo $环境变量
     ```

     例如：

     ![image-20220924112112854](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615119.png)

2.   **env**

     该命令可以让你在自定义的环境中运行程序，并且不需要改变当前的环境。当不带参数使用 `env` 命令时，它会打印出当前的环境变量列表。

     部分截图如下：

     ![image-20220924112341892](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615120.png)

3.   **printenv**

     可以打印出所有的或者指定的环境变量。默认状态下，`env` 和 `printenv` 的功能是完全相同的，只有在更具体的功能上才能体现出 `env` 命令与 `printenv` 命令的区别。例如，使用 `printenv` 命令，你可以查看单个环境变量：

     ![image-20220924112622285](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615121.png)

     `printenv` 亦命令检验该变量是否为环境变量：若无返回则不是环境变量

     ![image-20220924121112813](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615122.png)

4.   **set**

     使用set查看所有本地定义的shell变量和环境变量，通常搭配`grep`使用。

     ![image-20220924142651965](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615123.png)

## 常见环境变量

```shell
PATH 	:指定命令的搜索路径
HOME 	:指定用户的主工作目录(即用户登陆到Linux系统中时,默认的目录)
SHELL 	:当前Shell,它的值通常是/bin/bash。
TERM	:这指定运行 Shell 时要模拟的终端类型。可以针对不同的操作需求模拟不同的硬件终端。不过，你通常不需要管这个变量。
USER	:当前登录的用户
PWD		:当前的工作目录
OLDPWD		:上一个工作目录，这个变量由 Shell 保存，以便通过执行 cd - 切换回上一个工作目录。
LS_COLORS	:这定义了 ls 指令的颜色输出代码，用于向 ls 指令添加颜色输出。
MAIL	:当前用户邮箱的路径
LANG	:当前的语言和本地化设置，包括字符编码。
HOME	:当前用户的主目录
_		:上一个被执行的指令
```

### PATH

首先我们要知道，在Linux上，文件具有可执行权限我们就称之为一条命令。

![image-20220924104324802](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615124.png)

但是，为什么我们的命令不能像系统的命令一样直接使用，而是需要加上 `  ./` 或者完整路径名称才能执行？

![image-20220924103648464](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615125.png)

看下图：

![image-20220924104710011](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615126.png)

也就是说，系统曾经找过该命令，但是找不到。那么应该去哪儿找呢？其中OS（说法不对，暂且先这么理解）会通过环境变量` PATH` 辅助查找。换言之，`PATH`中保存的就是指令的搜索路径。

![image-20220924113255317](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615127.png)

其中，冒号作为路径分隔符，其余的是绝对路径。当你输入一条命令后，OS会在上述路径下寻找，若找不到，则会报错`-bash: proc: command not found`。

有了上述理解，我们很容易想到，如果OS能够按照上述方法搜索我们的命令，那么我们也可以像使用系统命令一样，不需要加上路径即可使用。故又下述2种方法：

-   将自己的可执行程序添加至系统路径下

![image-20220924114229315](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615128.png)

-   将自己的当前路径放入`PATH`下

![image-20220924114546379](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615129.png)

值得注意的是，`$`不可少，否则会清空`PATH`其他路径。倘若误操作，只需要关闭终端重新登陆即可。也就是说，该方法仅当前次有效。

### HOME

当我们使用不同身份登录时，我们的默认所处路径并不相同，查询结果也不同。如下：

![image-20220924120145665](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615130.png)

### SHELL

在Linux当中有许多种命令行解释器（例如bash、sh），我们可以通过查看环境变量SHELL来知道当前所用的命令行解释器。

![image-20220924120517119](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615131.png)

### PS1

大家有没有好奇每次的提示框里面是这样的？并且根用户提示符是`#`，普通用户是`$`，那我们能否修改呢？

![image-20220924124843679](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615132.png)

`echo $PS1`效果如下：

![image-20220924130010129](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615133.png)

其中，各参数含义如下：

```shell
\d 	:代表日期，格式为weekday month date，例如："Mon Aug 1"
\H 	:完整的主机名称
\h 	:仅取主机名中的第一个名字
\t 	:显示时间为24小时格式，如：HH：MM：SS
\T 	:显示时间为12小时格式
\A 	:显示时间为24小时格式：HH：MM
\u 	:当前用户的账号名称
\v 	:BASH的版本信息
\w 	:完整的工作目录名称
\W 	:利用basename取得工作目录名称，只显示最后一个目录名
\# 	:下达的第几个命令
\$ 	:提示字符，如果是root用户，提示符为 # ，普通用户则为 $
```

所以Linux默认的命令行提示信息的格式：`PS1='[\u@\h \W]\$ '`

## 获取环境变量

### 系统调用获取或设置环境变量

使用`getnev()`，头文件`stdlib.h`，函数原型`char *getenv(const char *name)`，使用如下：

```c++
#include <iostream>    
#include <unistd.h>    
#include <stdlib.h>    
    
using namespace std;    
    
int main()    
{    
    cout << "i am a process, ppid is: " << getppid() << endl; 
    cout << getenv("PATH") << endl;    
    cout << getenv("SHELL") << endl;    
    cout << getenv("USER") << endl;                                                                     
    return 0;    
}
```

结果如下：

![image-20220924133921528](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615134.png)

其中我们通过获取父进程PID发现，该进程的父进程执行者为`bash`。事实上，当我们在命令行上与运行的大部分命令，他们的父进程都是`bash`，`bash`创建子进程（`fork()`）来执行你的命令。

**命令行变量**

在命令行上我们可以定义两种变量：1. **本地变量**，2. **环境变量**。
其中本地变量只能在解释器内被访问，不可以被子进程继承，环境变量可以被继承。

![image-20220924141555265](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615135.png)

如上图，我们定义本地变量`MYVALUE="你好啊"`，本地解释器是可以访问的，而其子进程是无法获取到这一变量的，当我们使用`export`将其导入为环境变量后，其又是可以可以继承的。

不过，此时我们又有一个**疑问**：上文提及，当我们在命令行上与运行的大部分命令，他们的父进程都是`bash`，`bash`创建子进程（`fork()`）来执行你的命令。那么`echo`是命令吗？是的！那么，在`MYVALUE`导出为环境变量之前，为什么`myproc`命令无法获取到`MYVALUE`的值但是`echo`可以？这里我们就不得交代一下：`echo`是一个内建命令，shell内部的一个函数，若不是内建命令，才会创建子进程来执行。

**设置环境变量**

-   直接运行`export`命令定义变量【**只对当前shell(bash)有效(临时的)**】
-   在`/etc/profile`文件中添加变量【对所有用户生效(永久的)】
-   在用户目录下的`.bash_profile`文件中增加变量【对单一用户生效(永久的)】
-   `unset`：清除环境变量。

此时我们可以很好的理解`set`和 `env`的区别了。

![image-20220924142204874](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615136.png)

### 通过代码如何获取环境变量

我们知道，`main()`函数其实是可以带参数的。原型如下：

```c++
int main(int argc, char *argv[], char *envp[])
```

**命令行前两个参数**

讨论前两个参数，运行下列代码：

```C++
int main(int argc, char *argv[])
{
	for (int i = 0; i < argc; i++)
	{
		cout << argv[i] << endl;
	}
	return 0;
}
```

Linux结果如下：

![image-20220924183648380](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615137.png)

Windows结果如下：其中，VS中可以在项目->属性->调试->命令参数中添加命令行参数。

![image-20220924183345457](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615138.png)

其中，`argc`根据传入参数自动给出，`argv`是一个字符数组，关系如下图所示：

![image-20220924184503033](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615139.png)

那么为什么存在命令行参数呢？在Windows中我们很少能体会到其存在意义，不过在Linux中体验明显。例如`ls`，其携带不同的参数，实现不同功能。

```shell
[xcs101@VM-4-6-centos process]$ ls -a -l
```

因此，命令行参数存在的意义：帮助我们设计出同一个程序，设置出不同的业务功能。

**命令行第三个参数**

每个程序都会收到一张环境表，环境表是一个字符指针数组，每个指针指向一个以’\0’结尾的环境字符串。如下图所示：

![image-20220924203342905](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615140.png)

其中，我们通过第三个参数获取。使用如下所示：

```C++
int main(int argc, char *argv[], char *env[])
{
	for (int i = 0; env[i]; i++)
	{
		cout << env[i] << endl;
	}
	return 0;
}
```

`char *env[]`：其中，通过继承环境变量，实现环境变量被子进程继承下去，从而实现环境变量的 ”全局属性“。

**第三方变量**

除了上述方法外，我们还可以通过第三方变量来获取。适用方法同上。

```c++
extern char **environ;
```

-   因为`environ`是一个全局的外部变量，所以切记使用前要用`extern`关键字进行声明，然后再使用。

-   该变量在`unistd.h`中声明了，只需引用该头文件，就不用再对environ进行extern声明。

# 9. 进程地址空间

## 验证进程地址空间

大家一定有所了解过下面这张图：

![进程地址空间](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615141.png)

通过下列代码我们来验证一下：

```c
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>                                                                                          
int g_val = 0;
int g_uninit_val;      

int main(int argc, char *argv[], char *env[])    
{    
    printf("code addr is:           %p\n", main);    
    const char *r = "hello!\n";    
    printf("read only addr is:      %p\n", r);    
    printf("global addr is:         %p\n", &g_val);    
    printf("global uninit addr is:  %p\n", &g_uninit_val);    
    char *q1 = (char *)malloc(10);    
    char *q2 = (char *)malloc(10);    
    char *q3 = (char *)malloc(10);    
    printf("heap addr is:           %p\n", q1);    
    printf("heap addr is:           %p\n", q2);    
    printf("heap addr is:           %p\n", q3);    
    int a = 1;    
    int b = 2;    
    int c = 3;    
    printf("stack addr is:          %p\n", &a);    
    printf("stack addr is:          %p\n", &b);    
    printf("stack addr is:          %p\n", &c);    
    printf("args addr is:           %p\n", argv[0]);    
    printf("args addr is:           %p\n", argv[argc - 1]);    
    printf("env addr is:            %p\n", env[0]); 
    return 0;    
}
```

结果如下所示：

```shell
[xcs101@VM-4-6-centos Addr]$ ./checkaddr -a -b -c
code addr is:           0x40057d
read only addr is:      0x4007bc
global addr is:         0x601040
global uninit addr is:  0x601044
heap addr is:           0x167b010
heap addr is:           0x167b030
heap addr is:           0x167b050
stack addr is:          0x7ffed93effbc
stack addr is:          0x7ffed93effb8
stack addr is:          0x7ffed93effb4
args addr is:           0x7ffed93f1748
args addr is:           0x7ffed93f175a
env addr is:            0x7ffed93f175d
[xcs101@VM-4-6-centos Addr]$
```

我们知道，堆区由低地址向高地址增长，栈区则与之相反。为方便查看，我们将上述结果颠倒一下，其结果也是与之对应的。

![进程地址空间-测试结果](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615142.png)

其中，`static`修饰的变量生命周期决定其是全局的。我们将上述变量b修改为静态变量，结果如下：

![image-20220925180309451](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615143.png)

并且我们要知道，进程地址空间并不是内存！会在进程的整个生命周期内一直存在！

## 虚拟地址

接下来，我们再来一段代码。前置知识：在创建子进程前，这个全局变量`g_val`默认是父进程的。

```c
#include <stdio.h>    
#include <sys/types.h>                                             
#include <unistd.h>    
#include <stdlib.h>    
int g_val = 0;    
 
int main()    
{    
    printf("g_val is:%d, addr is:%p\n", g_val, &g_val);    
    pid_t ret = fork();    
    if(ret == 0)    
    {    
        //子进程    
        printf("i am child:g_val  is:%d, addr is:%p\n", g_val, &g_val);    
        sleep(5);    
        g_val = 100;    
        printf("i am child:g_val  is:%d, addr is:%p\n", g_val, &g_val);    
    }    
    else if(ret > 0)    
    {    
        //父进程    
        printf("i am father:g_val is:%d, addr is:%p\n", g_val, &g_val);    
        sleep(10);    
        printf("i am father:g_val is:%d, addr is:%p\n", g_val, &g_val);    
    }    
    else    
    {    
        perror("fork failed\n");    
        exit(1);
    }
    return 0;
}
```

结果如下：

![image-20220925212919330](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615144.png)

可以看到，父子进程地址一模一样，并且修改前后地址也是没有变的。这也证明了前面所说：代码共享，数据各自私有一份。同时如果我们看到的地址是物理地址，那么上述情况是绝对不可能发生的。所以说，我们曾经学到的地址绝对不会是物理地址。其本质是：**虚拟地址**，由操作系统提供。但是根据冯•诺依曼体系结构，数据和代码一定是加载到物理内存中的，而程序运行起来变成了进程，那么我们初步判断，虚拟地址与进程存在某种联系。

## 什么是进程地址空间

在前文的布局图中，我们看到其被划分为各个区域。进程地址空间从0x00000000到0xFFFFFFFF，就像是一把先天的尺子，通过记录各个边界的刻度，我们即可划分好区域。在Linux的源码中，`struct mm_struct`部分定义如下：

```c
struct mm_struct {
    struct vm_area_struct 	*mmap;		/* list of VMAs */
	struct rb_root 			mm_rb;		/* VMA形成的红黑树 */
    pgd_t * 				pgd;		/* 页全局目录 */
    atomic_t 				mm_users;	/* 使用地址空间的用户数 */
    atomic_t				mm_count;	/* 主使用计数器 */
    int 					map_count;	/* 主存区域的个数 */
    struct rw_semaphore 	mmap_lock;	/* 主存区域的信号量 */
	struct list_head 		mmlist;		/* 所有mm_struct形成的链表 */
	unsigned long 			start_code, end_code;	/* 代码段的开始地址，结束地址 */
    unsigned long			start_data, end_data;	/* 数据的首地址，尾地址 */
	unsigned long 			start_brk, brk, start_stack;	/* 堆的首地址，尾地址，进程栈的首地址 */
	unsigned long 			arg_start, arg_end;		/* 命令行参数的首地址，尾地址 */
    unsigned long			env_start, env_end;		/* 环境变量的首地址，尾地址 */
};
```

再来看待下图：![进程地址空间](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615141.png)
这是物理内存嘛？显然不是！这只是进程看待物理内存的一种方式。这种方式我们认为就是进程地址空间，在Linux中用`mm_struct`来描述。区域划分的本质：将地址空间划分为一个个的[start, end]。虚拟内存的本质：在[start, end]之间的各个地址。

我们知道用户栈是向下（高地址向低地址）增长，堆是向上（低地址向高地址）增长，在`mm_struct`中，通过调整`start_brk, brk, start_stack`等边界，即可实现。其中，每个`mm_struct`按照 4GB（32位下） 大小划分区域。换言之，每个进程都认为它拥有4GB内存大小。

同时根据冯•诺依曼体系结构，数据和代码一定是加载到物理内存中的，而我们得到的都是虚拟地址，也就是说，一定存在某种结构完成虚拟地址到物理地址的映射：也就是我们要提及的用户级**页表**。

![image-20220926121022415](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615145.png)

同时我们也可以回答上述代码：为什么父子进程的变量地址一样，但值不同？以及`fork()`的返回值有两个的情况？
当我们在执行`fork()`之前，以单进程执行流运行，父进程拥有自己的`task_struct`和`mm_struct`，PID。当子进程创建时，OS会为其分配子进程自己的`task_struct`，`mm_struct`以及唯一的 PID。同时子进程和父进程的数据和代码是共享的，即父子进程的代码和数据通过页表映射到物理内存的同一块空间。如下图所示：

![image-20220926142911348](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux5/202209261615146.png)

当这两个进程中的任一个后来进行写操作时，**写时拷贝（copy-on-write， COW）**机制就会创建新页面，将父进程的数据在内存当中拷贝一份，然后再进行修改。
这里存在几个疑问？

-   为什么数据要进行写时拷贝？
    我们知道进程之间具有独立性，为满足该点，数据各自私有一份。
    
-   为什么不实时拷贝？
    倘若直接把所有的资源复制给新创建的进程，这种实现过于简单并且效率低下，因为它拷贝的数据或许可以共享。更糟的是，如果新进程打算立即执行一个新的映像，那么所有的拷贝都将前功尽弃。例如，`fork()`后立即执行`exec()`，地址空间就无需被复制了。这种优化，可以避免拷贝大量根本就不会被使用的数据。并且这种延时分配可以高效的使用内存空间。
    
-   代码会不会进行写时拷贝？代码区一定是共享的吗？
    大部分情况下是共享的，不过也有例外。比如`fork()`后执行`exec()`。

## 为什么存在地址空间

1.   保护物理内存，不受到任何进程内的地址直接访问，方便进行合法性校验。

     我们进行区域划分后，[start, end] 可以帮我们进行有效范围的考量。比如一个数据区的变量，对代码区进行修改写入，则OS立即终止该进程。

2.   将内存管理和进程管理进行解耦。

     我们知道，操作系统负责：**内存管理**、**进程管理**、驱动管理、文件管理。假若没有页表，内存管理需要知道各进程的信息，以此来管理内存释放。反之通过页表的映射，内存管理只需要知道哪些内存区域是有效的，哪些是无效的即可。

3.   让每个进程以同样的方式看待代码和数据。

     比如说，进程运行时如何找到第一行代码？如果有地址空间，我们可以直接在某一确定位置完成代码的入口。

------
以上就是本次关于进程概念的简单总结，欢迎各位批评指正！