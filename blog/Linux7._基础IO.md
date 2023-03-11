[TOC]

------

# 前言

&emsp;&emsp;输入 / 输出( I / O )是在主存 (mainmemory ) 和外部设备（例如磁盘驱动器、终端和网络）之间拷贝数据的过程。 所有语言的运行时系统都提供执行 I/O 的较高级别的工具。 例如， C语言包含像 `printf` 和 `scanf` 这样执行带缓冲的 I/O 函数。 C++语言用它的重载操作符 `>>`输入 `<<`  输出 提供了类似的功能。大多数时候， 高级别 I/O 函数工作良好， 没有必要直接使用 Linux的IO函数，那么为什么还要学呢？

&emsp;&emsp;首先我们要知道，对文件的输入输出，都是对外设的输入输出，简称IO。

&emsp;&emsp;其次，相信当你接触Linux的时候，身边的人就向你灌输一个概念，或者说你就总是听到一句话:**Linux系统中一切皆文件**。普通文件、目录、字符设备、块设备和网络设备（套接字）等在Linux都被当做文件来对待。虽然他们的类型不同，但是Linux系统为它们提供了一套统一的操作接口。Linux的一切皆文件是指，Linux世界中的所有、任意、一切东西都可以通过文件的方式访问、管理。

![Linux下一切皆文件](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303061806862.png)

&emsp;&emsp;接下来要思考一个问题，空文件是否占用磁盘文件？答案是肯定的。例如文件的所属组、权限、文件名等。因此，文件 = 属性 + 内容。因此对文件的操作，无非是对属性和内容的操作。

![image-20230306150713428](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303061806864.png)

在系统角度来看，对文件的操作，即进程对文件的操作。

因此，学习系统调用接口意义如下:

+   更加贴近系统，通过系统接口窥探文件本质特征。

*   对于其它语言的学习，只要理解语法特征，底层已经清楚了。

# C语言文件IO

&emsp;&emsp;首先来回顾C语言所学的接口:

## 操作文件

**打开文件:`fopen`**

```c
#include <stdio.h>
FILE * fopen(const char *filename, const char *mode);
功能:打开文件
参数:
	filename:需要打开的文件名，这里可以是文件的绝对路径，也可以是相对路径
	mode:打开文件的模式设置
返回值:FILE* 这是一个结构体指针通过这个结构体指针可以操作文件
	成功:文件指针
	失败:NULL	
参数mode的几种形式:
r或rb	以只读方式打开一个文本文件（不会创建文件，若文件不存在则报错）
w或wb	以写方式打开文件(如果文件存在则清空文件，文件不存在则创建一个文件)
a或ab	以追加方式打开文件，在末尾添加内容，若文件不存在则创建文件
r+或rb+	以可读、可写的方式打开文件(不会创建新文件)
w+或wb+	以可读、可写的方式打开文件(如果文件存在则清空文件，文件不存在则创建一个文件)
a+或ab+	以添加方式打开文件，打开文件并在末尾更改文件,若文件不存在则创建文件          
```

**tips:**

+   b是二进制的意思，b只是在Windows下有效，在Linux下用r和rb的结果是一样的;
+   Linux下所有的文本文件行都是`\n`结尾，而Windows所有的文本文件行都是`\r\n`结尾；
+   一个进程**同时打开的文件数是有限制的**，超过最大同时打开文件数，再次调用`fopen`打开文件会失败。

**关闭文件: `fclose`**

```C
#include <stdio.h>
int fclose(FILE * stream);
功能:关闭先前fopen()打开的文件。此动作让缓冲区的数据写入文件中，并释放系统所提供的文件资源。
参数:
	stream:文件指针
返回值:
	成功:0
	失败:-1
```

**tips:**

+   打开的文件会占用内存资源，如果总是打开不关闭，会消耗很多内存;
+   如果没有明确的调用`fclose`关闭已打开的文件，那么程序在退出的时候，操作系统会统一关闭。

## 按字符读写文件

**写文件**

```c
#include <stdio.h>
int fputc(int ch, FILE * stream);
功能:将ch转换为unsigned char后写入stream指定的文件中
参数:
	ch:需要写入文件的字符
	stream:文件指针
返回值:
	成功:成功写入文件的字符
	失败:返回-1
```

**tips:**

+   使用EOF(end of file)来判断文件结尾，但是这种方式只能判断文本文件的结尾，可以使用`feof`函数。

**读文件**

```c
#include <stdio.h>
int fgetc(FILE * stream);
功能:从stream指定的文件中读取一个字符
参数:
	stream:文件指针
返回值:
	成功:返回读取到的字符
	失败:-1
```

## 按行读写文件

**写文件**

```c
#include <stdio.h>
int fputs(const char * str, FILE * stream);
功能:将str所指定的字符串写入到stream指定的文件中，字符串结束符 '\0'  不写入文件。 
参数:
	str:字符串
	stream:文件指针
返回值:
	成功:0
	失败:-1
```

**读文件**

```c
#include <stdio.h>
char * fgets(char * str, int size, FILE * stream);
功能:从stream指定的文件内读入字符，保存到str所指定的内存空间，直到出现换行字符、读到文件结尾或是已读了size - 1个字符为止，最后会自动加上字符 '\0' 作为字符串结束。
参数:
	str:字符串
	size:指定最大读取字符串的长度（size - 1）
	stream:文件指针
返回值:
	成功:成功读取的字符串
	读到文件尾或出错: NULL
```

## 按格式化文件

**写文件**

```c
#include <stdio.h>
int fprintf(FILE * stream, const char * format, ...);
功能:根据参数format字符串来转换并格式化数据，然后将结果输出到stream指定的文件中，指定出现字符串结束符 '\0'  为止。
参数:
	stream:已经打开的文件
	format:字符串格式，用法和printf()一样
返回值:
	成功:实际写入文件的字符个数
	失败:-1
```

**读文件**

```c
#include <stdio.h>
int fscanf(FILE * stream, const char * format, ...);
功能:从stream指定的文件读取字符串，并根据参数format字符串来转换并格式化数据。
参数:
	stream:已经打开的文件
	format:字符串格式，用法和scanf()一样
返回值:
	成功:参数数目，成功转换的值的个数
	失败: - 1
```

## 按块读写文件

**写文件**

```c
#include <stdio.h>
size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream);
功能:以数据块的方式给文件写入内容
参数:
	ptr:准备写入文件数据的地址
	size: size_t 为 unsigned int类型，此参数指定写入文件内容的块数据大小
	nmemb:写入文件的块数，写入文件数据总大小为:size * nmemb
	stream:已经打开的文件指针
返回值:
	成功:实际成功写入文件数据的块数目，此值和 nmemb 相等
	失败:0
```

**读文件**

```c
#include <stdio.h>
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
功能:以数据块的方式从文件中读取内容
参数:
	ptr:存放读取出来数据的内存空间
	size: size_t 为 unsigned int类型，此参数指定读取文件内容的块数据大小
	nmemb:读取文件的块数，读取文件数据总大小为:size * nmemb
	stream:已经打开的文件指针
返回值:
	成功:实际成功读取到内容的块数，如果此值比nmemb小，但大于0，说明读到文件的结尾。
	失败:0
```

## 随机读写文件

```c
#include <stdio.h>
long ftell(FILE *stream);
功能:获取文件流（文件光标）的读写位置。
参数:
	stream:已经打开的文件指针
返回值:
	成功:当前文件流（文件光标）的读写位置
	失败:-1
```

```c
#include <stdio.h>
int fseek(FILE *stream, long offset, int whence);
功能:移动文件流（文件光标）的读写位置。
参数:
	stream:已经打开的文件指针
	offset:根据whence来移动的位移数（偏移量），可以是正数，也可以负数，如果正数，则相对于whence往右移动，如果是负数，则相对于whence往左移动。如果向前移动的字节数超过了文件开头则出错返回，如果向后移动的字节数超过了文件末尾，再次写入时将增大文件尺寸。
	whence:其取值如下:
		SEEK_SET:从文件开头移动offset个字节
		SEEK_CUR:从当前位置移动offset个字节
		SEEK_END:从文件末尾移动offset个字节
返回值:
	成功:0
	失败:-1
```

```c
#include <stdio.h>
void rewind(FILE *stream);
功能:把文件流（文件光标）的读写位置移动到文件开头。
参数:
	stream:已经打开的文件指针
返回值:
	无返回值
```

## 文件其他操作

```c
#include <sys/types.h>
#include <sys/stat.h>
int stat(const char *path, struct stat *buf);
功能:获取文件状态信息
参数:
    path:文件名
    buf:保存文件信息的结构体
返回值:
    成功:0
    失败-1
    
struct stat {
	dev_t         st_dev;     	//文件的设备编号
	ino_t         st_ino;       //节点
	mode_t        st_mode;   	//文件的类型和存取的权限
	nlink_t       st_nlink;     //连到该文件的硬连接数目，刚建立的文件值为1
	uid_t         st_uid;       //用户ID
	gid_t         st_gid;       //组ID
	dev_t         st_rdev;      //(设备类型)若此文件为设备文件，则为其设备编号
	off_t         st_size;      //文件字节数(文件大小)
	unsigned long st_blksize;   //块大小(文件系统的I/O 缓冲区大小)
	unsigned long st_blocks;    //块数
	time_t        st_atime;     //最后一次访问时间
	time_t        st_mtime;    	//最后一次修改时间
	time_t        st_ctime;     //最后一次改变时间(指属性)
};    
```

```c
#include <stdio.h>
int remove(const char *pathname);
功能:删除文件
参数:
	pathname:文件名
返回值:
	成功:0
	失败:-1 
```

```c
#include <stdio.h>
int rename(const char *oldpath, const char *newpath);
功能:把oldpath的文件名改为newpath
参数:
    oldpath:旧文件名
    newpath:新文件名
返回值:
    成功:0
    失败: - 1
```

```c
 #include <stdio.h>
int fflush(FILE *stream);
功能:更新缓冲区，让缓冲区的数据立马写到文件中。
参数:
    stream:文件指针
返回值:
    成功:0
    失败:-1
```

```c
#include <stdio.h>
int feof(FILE * stream);
功能:检测是否读取到了文件结尾。判断的是最后一次“读操作的内容”，不是当前位置内容(上一个内容)。
参数:
	stream:文件指针
返回值:
	非0值:已经到文件结尾
	0:没有到文件结尾
```

## 路径

&emsp;&emsp;通常来说，我们打开某一文件，需为相对路径或绝对路径，但我们也可以仅有文件名（即为当前路径）的写法。有下列代码：

```c
#include <stdio.h>

int main()
{
    const char* path = "log.txt";
    FILE* fp = fopen(path, "w");
    if(fp == NULL)
    {
        perror("fopen failed\n");
        return 1;
    }
    int count = 0;
    while(count < 5)
    {
        fputc(count + '0', fp);
        fputs(":> hello world\n", fp);
        count++;
    }

    fclose(fp);

    return 0;
}
```

我们在**iobase**目录下运行，可以发现在此目录下多出**log.txt**文件；

![image-20230306170255710](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303061806865.png)

在**iobase**的上级目录**blog**下运行，可以发现在**blog**目录下多出**log.txt**文件。

![image-20230306170620441](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303061806866.png)

可以发现，该可执行程序运行后并没有在**iobase**目录下创建**log.txt**文件，而是在我们当前所处的路径下创建了**log.txt**文件。

此外，我们将该程序改为死循环后继续运行，分别在**iobase**目录下运行后，并查看进程信息，如下：

![image-20230306172324714](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303061806867.png)

在**iobase**的上级目录**blog**下运行，结果如下：

![image-20230306172700527](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303061806868.png)

可以看到，`cwd`就是进程运行时我们所处的路径，而`exe`就是该可执行程序的所处路径。

## stdin & stdout & stderr

&emsp;&emsp;有了上述基础后，我们再来看**Linux下一切皆文件**。我们知道，若对某一文件操作，则必须先打开该文件。由下图可知，键盘，显示器亦是文件，但我们可以直接使用`printf`、`scanf`、`cin`、`cout`等函数直接对其写入数据。换言之，为何不用打开该文件？

![Linux下一切皆文件](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303091718031.png)

&emsp;&emsp;事实上，任何c程序，都会默认打开三个"文件"（实际上是文件指针）,标准输入（stdin），标准输出（stdout），标准错误（stderr）。通过`man`手册，我们可以看到他们是**FILE***类型。

```c
NAME
       stdin, stdout, stderr - standard I/O streams
SYNOPSIS
       #include <stdio.h>

       extern FILE *stdin;		//键盘文件
       extern FILE *stdout;		//显示器文件
       extern FILE *stderr;		//显示器文件
```

**对于c程序为什么会默认打开stdin，stdout，stderr:**
&emsp;&emsp;便于语言进行上手使用，且几乎任何语言都是如此。故这不是语言层提供的功能，而是系统层面提供的了。

# 系统调用接口

&emsp;&emsp;针对不同系统，各种语言对其系统调用接口进行了封装，在不同系统中，有着统一的操作方法，大大提高了可移植性。

![image-20230307164824121](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303091718032.png)

对于**文件读写操作**，有下列调用接口，简单介绍几个接口。

| 系统调用  |             描述             |
| :-------: | :--------------------------: |
|   fcntl   |           文件控制           |
|   open    |           打开文件           |
|   creat   |          创建新文件          |
|   close   |        关闭文件描述字        |
|   read    |            读文件            |
|   write   |            写文件            |
|   readv   |  从文件读入数据到缓冲数组中  |
|  writev   |  将缓冲数组里的数据写入文件  |
|   pread   |         对文件随机读         |
|  pwrite   |         对文件随机写         |
|   lseek   |         移动文件指针         |
|  _llseek  | 在64位地址空间里移动文件指针 |
|    dup    |    复制已打开的文件描述字    |
|   dup2    |   按指定条件复制文件描述字   |
|   flock   |         文件加/解锁          |
|   poll    |         I/O多路转换          |
| truncate  |           截断文件           |
| ftruncate |           截断文件           |
|   umask   |       设置文件权限掩码       |
|   fsync   | 把文件在内存中的部分写回磁盘 |

## open

函数原型如下：

```c
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int open(const char *pathname, int flags);
int open(const char *pathname, int flags, mode_t mode);
```

**返回值**

-   返回一个文件描述符，当文件成功打开时，返回一个非负整数，当文件打开失败时，返回-1

**参数**

-   **const char \*pathname：** 文件路径名（绝对路径）或者文件名

-   **int flags :**  文件打开方式

    |  参数选项  |                     参数功能                      |
    | :--------: | :-----------------------------------------------: |
    |  O_RDONLY  |                       只读                        |
    |  O_WRONLY  |                       只写                        |
    |   O_RDWR   |                     可读可写                      |
    |  O_CREAT   |   该文件不存在则创建它，需要搭配第三个参数使用    |
    |  O_APPEND  |                     追加写入                      |
    |  O_TRUNC   |                     清空内容                      |
    |   O_EXCL   | 如果同时指定了O_CREAT，并且文件已存在，则出错返回 |
    | O_NONBLOCK |                      非阻塞                       |

    在Linux中，由于一个`int`类型有32个比特位，可用每个二进制位定义一个选项。因此可用`|`选择多个参数。

    ```c
    #define O_RDONLY            0
    #define O_WRONLY            1
    #define O_RDWR              2
    #define O_CREAT          0x40
    #define O_EXCL           0x80
    #define O_NOCTTY        0x100
    #define O_TRUNC         0x200
    #define O_APPEND        0x400
    #define O_NONBLOCK      0x800
    #define O_DIRECTORY   0x10000
    ```

    故可有下列写法：

    ```c
    O_WRONLY | O_CREAT
    ```

-   **mode_t mode :** 创建文件的默认权限

    该参数一定是`flags`中使用了`O_CREAT`标志，`mode`记录待创建的文件的访问权限。通常以八进制数表示，如`0644`。且权限会受到umask的影响。

## close

函数原型如下：

```c
#include <unistd.h>

int close(int fd);
```

**返回值**

-   成功返回0；失败返回-1，并设置错误码。

**参数**

-   **int fd ：** 需要关闭的文件描述符。

## write

函数原型如下：

```c
#include <unistd.h>

ssize_t write(int fd, const void *buf, size_t count);
```

**返回值**

-   成功返回写入的字节数，失败返回-1。

**参数**

-   **int fd ：** 需要写入的文件描述符。
-   **const void \*buf ：** 指定存储器写入数据的缓冲区。
-   **size_t count ：** 指定写入的字节数。

## read

函数原型如下：

```c
#include <unistd.h>

ssize_t read(int fd, void *buf, size_t count);
```

**返回值**

-   成功返回实际读取的字节数，失败返回-1。

**参数**

-   **int fd ：** 需要读取的文件描述符。
-   **const void \*buf ：** 指定存储器读出数据的缓冲区。
-   **size_t count ：** 指定读取的字节数。

# 文件描述符（file descriptor）

&emsp;&emsp;在前面的系统调用接口中，我们可以看到参数`int fd`，事实上，`fd`是**文件描述符（file descriptor）**的简称。先运行下列代码：

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()    
{    
    int fd0 = open("log0.txt", O_RDWR|O_CREAT, 0644);
    int fd1 = open("log1.txt", O_RDWR|O_CREAT, 0644);
    int fd2 = open("log2.txt", O_RDWR|O_CREAT, 0644);
    int fd3 = open("log3.txt", O_RDWR|O_CREAT, 0644);
    int fd4 = open("log4.txt", O_RDWR|O_CREAT, 0644);
    int fd5 = open("log5.txt", O_RDWR|O_CREAT, 0644);

    printf("fd0:%d\n", fd0);
    printf("fd1:%d\n", fd1);
    printf("fd2:%d\n", fd2);
    printf("fd3:%d\n", fd3);
    printf("fd4:%d\n", fd4);
    printf("fd5:%d\n", fd5);
    
    close(fd0);
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
    close(fd5);
	return0;
}
```

无论运行多少次，可以看到，fd从3开始，且为连续的小整数。

![image-20230309110445889](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303091718033.png)

这和数组下标有点相似。但是，`0、1、2`去哪儿呢？别忘记了前文所述：任何一个C程序默认打开`stdin、stdout、stderr`三个输入输出流。换言之，`0、1、2`对应上述3个输入输出流，故`fd`从下标3开始。其中这三个输入输出流对应的名为`stdin`，`stdout`，`stderr`，文件类型为`FILE*`，而`FILE*`是C语言的概念，底层对应的文件描述符，其中`stdin`对应0，`stdout`对应1，`stderr`对应2。

&emsp;&emsp;在**Linux中一切文件**，文件可分为：普通文件、目录文件、链接文件和设备文件。而进程可能会打开各种各样的文件，所以系统中在任何时刻都可能存在大量已经打开的文件，操作系统的功能之一就是**文件管理**，就是要对这些打开的文件进行管理。在Linux中有六字箴言：**先描述再组织**。

&emsp;&emsp;底层中描述文件的数据结构叫做**`struct file`**，一个文件对应一个**`struct file`**，大量的文件就有大量的**`struct file`**，我们只需将这些数据结构用双链表连接起来，所以对文件的管理就变成了对双链表的增删改查。其`fs.h`中定义如下：

```c
struct file {
	union {
		struct llist_node	f_llist;
		struct rcu_head 	f_rcuhead;
		unsigned int 		f_iocb_flags;
	};
	struct path		f_path;
	struct inode		*f_inode;	/* cached value */
	const struct file_operations	*f_op;

	/*
	 * Protects f_ep, f_flags.
	 * Must not be taken from IRQ context.
	 */
	spinlock_t		f_lock;
	atomic_long_t		f_count;
	unsigned int 		f_flags;
	fmode_t			f_mode;
	struct mutex		f_pos_lock;
	loff_t			f_pos;
	struct fown_struct	f_owner;
	const struct cred	*f_cred;
	struct file_ra_state	f_ra;

	u64			f_version;
#ifdef CONFIG_SECURITY
	void			*f_security;
#endif
	/* needed for tty driver, and maybe others */
	void			*private_data;

#ifdef CONFIG_EPOLL
	/* Used by fs/eventpoll.c to link all the hooks to this file */
	struct hlist_head	*f_ep;
#endif /* #ifdef CONFIG_EPOLL */
	struct address_space	*f_mapping;
	errseq_t		f_wb_err;
	errseq_t		f_sb_err; /* for syncfs */
} __randomize_layout
```

&emsp;&emsp;而我们要做的就是建立进程和文件的对应关系。所以Linux中规定每一个文件对应一个索引，这样要操作文件的时候，我们直接找到索引就可以对其进行操作了。文件描述符（file descriptor）就是内核为了高效管理这些已经被打开的文件所创建的索引，其是一个非负整数（通常是小整数），用于指代被打开的文件，所有执行I/O操作的系统调用都通过文件描述符来实现。

&emsp;&emsp;每一个进程都有一个**`task_strut`**，这个**`task_struct`**会指向一个**`struct files_struct`**结构体，

```c
/* Filesystem information: */
struct fs_struct		*fs;

/* Open file information: */
struct files_struct		*files;
```

&emsp;&emsp;这个结构体里会有一个指针数组**`struct file* fd_array[NR_OPEN_DEFAULT]`**，而这个指针数组就是文件描述符对应的数组。每个进程用一个**`files_struct`**结构来记录文件描述符的使用情况，这个**`files_struct`**结构称为用户打开文件表，它是进程的私有数据。

```c
struct files_struct {
  /*
   * read mostly part
   */
	atomic_t count;
	bool resize_in_progress;
	wait_queue_head_t resize_wait;

	struct fdtable __rcu *fdt;
	struct fdtable fdtab;
  /*
   * written part on a separate cache line in SMP
   */
	spinlock_t file_lock ____cacheline_aligned_in_smp;
	unsigned int next_fd;
	unsigned long close_on_exec_init[1];
	unsigned long open_fds_init[1];
	unsigned long full_fds_bits_init[1];
	struct file __rcu * fd_array[NR_OPEN_DEFAULT];
};
```

其中，**`NR_OPEN_DEFAULT`**为默认打开的最大文件数。

而已打开的文件在内核中用`struct file`表示。

-   在`file`结构体中维护File Status Flag（`file`结构体的成员`f_flags`）和当前读写位置（`file`结构体的成员`f_pos`）。
-   `file`结构体中比较重要的成员还有`f_count`，表示引用计数（Reference Count）。`dup`、`fork`等系统调用会导致多个文件描述符指向同一个`file`结构体，例如有`fd1`和`fd2`都引用同一个`file`结构体，那么它的引用计数就是2，当`close(fd1)`时并不会释放`file`结构体，而只是把引用计数减1，如果再`close(fd2)`，引用计数就会减到0同时释放`file`结构体，这才真的关闭了文件。

-   每个`file`结构体都指向一个`file_operations`结构体，这个结构体的成员都是函数指针，指向实现各种文件操作的内核函数。比如在用户程序中`read`一个文件描述符，`read`通过系统调用进入内核，然后找到这个文件描述符所指向的`file`结构体，找到`file`结构体所指向的`file_operations`结构体，调用它的`read`成员所指向的内核函数以完成用户请求。在用户程序中调用`lseek`、`read`、`write`、`ioctl`、`open`等函数，最终都由内核调用`file_operations`的各成员所指向的内核函数完成用户请求。![文件描述](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303091718034.png)

**文件描述符分配规则**：**在`fd_array`当中，找到当前没有被使用的最小的一个下标，作为新的文件描述符。**

运行下列代码：

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

int main()    
{    
    int fd0 = open("log0.txt", O_RDWR|O_CREAT, 0644);
    int fd1 = open("log1.txt", O_RDWR|O_CREAT, 0644);
    int fd2 = open("log2.txt", O_RDWR|O_CREAT, 0644);
    int fd3 = open("log3.txt", O_RDWR|O_CREAT, 0644);
    int fd4 = open("log4.txt", O_RDWR|O_CREAT, 0644);
    int fd5 = open("log5.txt", O_RDWR|O_CREAT, 0644);

    printf("fd0:%d\n", fd0);
    printf("fd1:%d\n", fd1);
    printf("fd2:%d\n", fd2);
    printf("fd3:%d\n", fd3);
    printf("fd4:%d\n", fd4);
    printf("fd5:%d\n", fd5);
    
    close(fd0);
    close(fd1);
    close(fd2);
    close(fd3);
    close(fd4);
    close(fd5);
	return0;
}
```

结果如下：

![image-20230309110445889](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303091718033.png)

倘若我们先关闭0号文件，结果如下图所示：

![image-20230309164011049](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303091718035.png)

若先关闭0号和2号文件，结果如下：

![image-20230309164151602](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303091718036.png)

# 重定向

首先来段代码感受一下：

```c
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()    
{
    close(1);
    int fd = open("log.txt", O_WRONLY|O_CREAT, 0644);

    printf("hello world\n");
    printf("hello world\n");
    printf("hello world\n");
    printf("hello world\n");
    printf("hello world\n");
    
    fflush(stdout);
    close(fd); 
    return 0;
}
```

结果如下图所示：

![image-20230309170004058](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303091718018.png)

可以看到，本应该打印到屏幕上的内容被写入到**log.txt**中。

根据文件描述符分配规则可知，原本应该打开的标准输出流位置，指向**log.txt**文件。如此一来，我们就将数据输出重定向到了**log.txt**文件中。

![重定向内核描述](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303112200913.png)

然而，倘若**无`fflush(stdout); `**，文件**log.txt**内容却为空。接下来聊聊`FILE`与`int fd`的关系。

## 缓冲区刷新策略

在`/usr/include/stdio.h  `中可以看到，`typedef struct _IO_FILE FILE  `，在`在/usr/include/libio.h  `中有如下定义：

```C
struct _IO_FILE {    
  int _flags;       /* High-order word is _IO_MAGIC; rest is flags. */    //缓冲方式
#define _IO_file_flags _flags    
	//缓冲区相关
  /* The following pointers correspond to the C++ streambuf protocol. */    
  /* Note:  Tk uses the _IO_read_ptr and _IO_read_end fields directly. */    
  char* _IO_read_ptr;   /* Current read pointer */    
  char* _IO_read_end;   /* End of get area. */    
  char* _IO_read_base;  /* Start of putback+get area. */    
  char* _IO_write_base; /* Start of put area. */    
  char* _IO_write_ptr;  /* Current put pointer. */    
  char* _IO_write_end;  /* End of put area. */    
  char* _IO_buf_base;   /* Start of reserve area. */    
  char* _IO_buf_end;    /* End of reserve area. */    
  /* The following fields are used to support backing up and undo. */    
  char *_IO_save_base; /* Pointer to start of non-current get area. */    
  char *_IO_backup_base;  /* Pointer to first valid character of backup area */    
  char *_IO_save_end; /* Pointer to end of non-current get area. */    
    
  struct _IO_marker *_markers;    
    
  struct _IO_FILE *_chain;    
    
  int _fileno;   //封装的文件描述符 
#if 0    
  int _blksize;    
#else    
  int _flags2;    
#endif    
  _IO_off_t _old_offset; /* This used to be _offset but it's too small.  */

#define __HAVE_COLUMN /* temporary */
  /* 1+column number of pbase(); 0 is unknown. */
  unsigned short _cur_column;
  signed char _vtable_offset;
  char _shortbuf[1];

  /*  char* _save_gptr;  char* _save_egptr; */

  _IO_lock_t *_lock;
#ifdef _IO_USE_OLD_IO_FILE
};
```

由上述定义可以看到，**`FILE`**结构体不仅对文件描述符进行了封装，还有对缓冲区的封装。

其中，**`FILE`**结构和文件描述符、file结构之间的关系可以用下图来表示：



![FILE与内核](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303112159596.png)

当用户关闭标准输出并打开新的文件后，看起来仅仅是`fd`的指向关系发生变化，实际上缓冲区的刷新策略亦发生变化。

首先来点预备知识：

```c
#include <stdio.h>
int setvbuf(FILE *stream, char *buf, int mode, size_t size);
```

**返回值**

-   成功返回0，失败返回非0。

**参数**

-   **FILE *stream ：**要操作的流对象。
-   **char *buf ：**指向一个长为BUFSIZ 的缓冲区。
-   **int mode ：** 缓冲区类型。
    -   **全缓冲：**`#define _IOFBF 0 /* Fully buffered.*/  `
    -   **行缓冲：**`#define _IOLBF 1 /* Line buffered. */`
    -   **无缓冲：**`#define _IONBF 2 /* No buffering. */ `

-   **size_t size ：**该buf的大小。如果指定一个不带缓冲区的流（即buf为NULL)，则忽略buf和size参数。

```c
/* unsupported */
#include <stdio.h>

int fpurge(FILE *stream);

/* supported */
#include <stdio.h>
#include <stdio_ext.h>

void  __fpurge(FILE *stream);
```

查询可知，`fpurge()`函数不再支持。

**功能**

-   函数`__fpurge()`清除给定流中的缓冲区。对于输出流，这将丢弃任何未写入的输出。对于输入流，该函数将丢弃从底层对象读取但尚未通过`getc()`获得的任何输入;这包括通过`ungetc()`推回来的任何文本。

**参数**

-   **FILE \*stream ：**要清空的给定流。

**错误码**

-   ​    **EBADF** 流没有打开。

有上述知识背景后，我们再来运行下列代码：

```c
#include <stdio.h>    
#include <unistd.h>    
#include <fcntl.h>    
#include <sys/types.h>    
#include <sys/stat.h>    
#include <string.h>    
#include <stdio_ext.h>    
    
int main()    
{    
    //自定义缓冲区    
    char buf[512];    
    memset(buf, '\0', 512);    
    //测试stdout默认缓冲区    
    //printf("Test");    
    __fpurge(stdout);    
    if (stdout->_flags & _IO_UNBUFFERED)                /* 无缓冲 */    
        printf("stdout Unchange:Un Buffered\n");    
    else if (stdout->_flags & _IO_LINE_BUF)             /* 行缓冲 */    
        printf("stdout Unchange:Line Buffered\n");    
    else                                                /* 全缓冲 */    
        printf("stdout Unchange:Fully Buffered\n");    

    //setvbuf(stdout, buf, _IOFBF, 512);					//设为全缓冲
    close(1);   //关闭stdout
    int fd = open("log.txt", O_WRONLY|O_CREAT, 0644);   //打开普通文件
    //判断缓冲区类型是否改变
    if (stdout->_IO_file_flags & _IO_UNBUFFERED)        /* 无缓冲 */
        printf("Unchange:Un Buffered\n");
    else if (stdout->_IO_file_flags & _IO_LINE_BUF)     /* 行缓冲 */
        printf("Unchange:Line Buffered\n");
    else                                                /* 全缓冲 */
        printf("Unchange:Fully Buffered\n");
    
    //printf("hello fd:%d\n", fd);
    fflush(stdout);
    __fpurge(stdout);
    
    //自定义为不同类型缓冲区
    setvbuf(stdout, buf, _IONBF, 512);
    if (stdout->_IO_file_flags & _IO_UNBUFFERED)        /* 无缓冲 */
        printf("set0 for first :Un Buffered\n");
    else if (stdout->_IO_file_flags & _IO_LINE_BUF)     /* 行缓冲 */
        printf("set0 for first :Line Buffered\n");
    else                                                /* 全缓冲 */
        printf("set0 for first :Fully Buffered\n");
    __fpurge(stdout);
    
    setvbuf(stdout, buf, _IOLBF, 512);
    if (stdout->_IO_file_flags & _IO_UNBUFFERED)        /* 无缓冲 */
        printf("set1 for second:Un Buffered\n");
    else if (stdout->_IO_file_flags & _IO_LINE_BUF)     /* 行缓冲 */
        printf("set1 for second:Line Buffered\n");
    else                                                /* 全缓冲 */
        printf("set1 for second:Fully Buffered\n");
	__fpurge(stdout);
    
    setvbuf(stdout, buf, _IOFBF, 512);
    if (stdout->_IO_file_flags & _IO_UNBUFFERED)        /* 无缓冲 */
        printf("set2 for third :Un Buffered\n");
    else if (stdout->_IO_file_flags & _IO_LINE_BUF)     /* 行缓冲 */
        printf("set2 for third :Line Buffered\n");
    else                                                /* 全缓冲 */
        printf("set2 for third :Fully Buffered\n");
    __fpurge(stdout);
    
    close(fd);
    
	return 0;
}
```

运行结果如下图所示：

![image-20230310235236002](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303112159768.png)

取消对**`printf("Test");`**的注释，结果如下：

![image-20230310234750533](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303112159495.png)

再取消对24行**`setvbuf(stdout, buf, _IOFBF, 512);`**的注释，结果如图：

![image-20230311000248207](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303112158181.png)

可以看到，对于**标准输出**，其在关闭前是否涉及到**设备交互**，影响着后续文件的缓冲区策略。即原**`stdout`**中的刷新策略并未改变。

因此，我们将一开始代码做出如下调整：

```C
	printf("stdout\n");    
    close(1);    
    int fd = open("log.txt", O_WRONLY|O_CREAT, 0644);    
    
    printf("hello world\n");    
    printf("hello world\n");    
    printf("hello world\n");    
    printf("hello world\n");    
    printf("hello world\n");    
    
    //fflush(stdout);    
    close(fd);      
```

由结果可以看出，即便不再使用**`fflush`**对缓冲区刷新，其内容依旧可以重定向到普通文件中。

![image-20230311000542795](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303112200282.png)

事实上，花了如此多的文笔，只是为展现下列**缓冲区特征**：

-   **标准输入和标准输出设备**：当且仅当不涉及到设备交互作用时，标准输入流和标准输出流才是全缓冲区的。
-   **标准出错输出设备**：标准出错绝不会是全缓冲区的。

因此，部分博主在以上述代码解释重定向的时候，并未考虑到这一点，而解释为：~~由于打开的文件类型不同，导致其刷新策略变化，进而影响重定向后内容的读写~~。这是有待商榷的。

## 通过文件描述符获取文件名

为何会突然说到这个呢？先来看一下下列代码：

```c
#include <stdio.h>    
#include <unistd.h>    
#include <fcntl.h>    
#include <sys/types.h>    
#include <sys/stat.h>    
#include <string.h>    
#include <stdio_ext.h>    
    
int main()    
{    
	printf("hello printf\n");
    fputs("hello fputs\n", stdout);
    write(1, "hello write\n", 12);
    fflush(stdout);
    fork();
    
    return 0;
}
```

在**指令**那一节，我们初步认识了重定向。在此，我们也将程序的结果重定向到**log.txt**文件当中。结果如下，毫无疑问。

![image-20230311195121475](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303112200283.png)

对`fflush(stdout)`注释后，结果如下图所示：

![image-20230311195701086](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303112200284.png)

可以看到，除了`hello write\n`输出一次外，其余均输出了两次。我们暂不考虑这一点。

有了前文的了解，我们就会联想到**设备交互**的问题。因此，我们将`fork()`后的代码做如下修改：

```c
if(fork() == 0)    
{    
    if (stdout->_flags & _IO_UNBUFFERED)                /* 无缓冲 */    
        printf("father\'s buf:Un Buffered\n");    
    else if (stdout->_flags & _IO_LINE_BUF)             /* 行缓冲 */    
        printf("father\'s buf:Line Buffered\n");    
    else                                                /* 全缓冲 */    
        printf("father\'s buf:Fully Buffered\n");    
}    
else    
{    
    if (stdout->_flags & _IO_UNBUFFERED)                /* 无缓冲 */    
        printf("child buf:Un Buffered\n");    
    else if (stdout->_flags & _IO_LINE_BUF)             /* 行缓冲 */    
        printf("child buf:Line Buffered\n");    
    else                                                /* 全缓冲 */    
        printf("child buf:Fully Buffered\n");    
} 
```

结果如下图所示：

![image-20230311200604401](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303112200286.png)

可以看到，未重定向时，标准输出的缓冲策略变为行刷新，重定向后，标准输出的刷新策略并未改变，仍是全缓冲。但是，我们并未关闭`fd = 1`的文件，那么，究竟是结果的重定向，还是程序运行前，系统将其”替换“了呢？亦或是其他博主所言，文件的类型导致刷新策略的变化呢？

为此，我们来了解下列函数：

```
int snprintf(char *str, size_t size, const char *format, ...);
```

**功能：**

-   将可变个参数(…)按照format格式化成字符串，然后将其复制到str中。

**返回值**：

-   该函数返回实际写入的字符数（不包括NULL结尾）。

**参数：**

-   **s：**指向要存储字符串（由format参数格式化）的字符数组。

-   **n：**指定存储字符串的最大字符数（不包括NULL结尾）。

-   **format：**是格式字符串，用于格式化输出字符串。

**tips：**

-   如果格式化后的字符串长度 < size，则将此字符串全部复制到str中，并给其后添加`'\0'`；

-   如果格式化后的字符串长度 >= size，则只将其中的(size-1)个字符复制到str中，并给其后添加`'\0'`，返回值为欲写入的字符串长度。

```c
#include <unistd.h>
ssize_t readlink(const char *path, char *buf, size_t bufsiz);
```

**功能：**

-   `readlink()`会将参数path的符号连接内容到参数buf所指的内存空间，返回的内容不是以NULL作字符串结尾，但会将字符串的字符数返回。若参数bufsiz小于符号连接的内容长度，过长的内容会被截断

**参数：**

-   **const char *path：**连接名（路径）。
-   **char *buf：**缓冲区（缓存读出的数据）。
-   **size_t bufsiz：**缓冲区大小。

**返回值：**

-   成功返回缓冲区被填充的大小。
-   失败返回-1且设置errno。

有上述函数，我们可以通过下列代码，获取进程打开的文件名。

```
#include <stdio.h>    
#include <unistd.h>    
#include <fcntl.h>    
#include <sys/types.h>    
#include <sys/stat.h>    
#include <string.h>    
#include <stdio_ext.h>    
    
int main()    
{    	
	char buf[1024] = {'\0'};                   
    char file_path[1024] = {'\0'};    
    snprintf(buf, sizeof(buf), "/proc/self/fd/%d", 1);    
    readlink(buf, file_path, sizeof(file_path)-1);                                                       
    printf("fd:1, name is:%s\n", file_path); 
    
    printf("hello printf\n");
    fputs("hello fputs\n", stdout);
    write(1, "hello write\n", 12);
    
    if(fork() == 0)    
    {    
        if (stdout->_flags & _IO_UNBUFFERED)                /* 无缓冲 */    
            printf("father\'s buf:Un Buffered\n");    
        else if (stdout->_flags & _IO_LINE_BUF)             /* 行缓冲 */    
            printf("father\'s buf:Line Buffered\n");    
        else                                                /* 全缓冲 */    
            printf("father\'s buf:Fully Buffered\n");    
    }    
    else    
    {    
        if (stdout->_flags & _IO_UNBUFFERED)                /* 无缓冲 */    
            printf("child buf:Un Buffered\n");    
        else if (stdout->_flags & _IO_LINE_BUF)             /* 行缓冲 */    
            printf("child buf:Line Buffered\n");    
        else                                                /* 全缓冲 */    
            printf("child buf:Fully Buffered\n");    
    } 
    
    return 0;
}
```

结果如下图所示：

![image-20230311204656150](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303112200287.png)

可以看到，未重定向时`fd = 1`所指向的文件为`/dev/pts/0`，重定向后指向`log.txt`。

![image-20230311205723957](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303112200288.png)

![image-20230311210554989](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303112200304.png)

## 用户级缓冲区和内核级缓冲区的联系

至此，我们可以来解释剩余问题：为何`write`只执行一次。通常我们将`write`函数看作是没有缓冲区的。并且我们谈论的缓冲区是**用户级缓冲区**，由C语言提供，由`FILE`结构体维护。而操作系统实际上也是有缓冲区的（**内核级缓冲区**，在`struct file`结构体）。

1.   `write`写入接口，实际上并不是直接将数据写到磁盘中，而是将数据写到内核缓冲区里面，而且`fflush`也不是将数据刷新到磁盘里，而是将数据从用户级缓冲区刷新到内核缓冲区里，**最后由操作系统自主决定将内核缓冲区的数据刷新到磁盘上**。

2.   我们无需关心操作系统缓冲区的刷新规则，**因为操作系统需要兼顾整体内存的使用情况，来决定是否进行内核缓冲区的刷新**。

3.   **所以C函数的写入，首先将内容拷贝到FILE中的用户级缓冲区里，然后通过系统调用write将数据从FILE中的用户缓冲区中刷新到file结构体中的内核级缓冲区，最后再由操作系统自主决定将内核级缓冲区的数据刷新到外设物理媒介上。**

4.   **内核缓冲区刷新数据到磁盘上，这个过程和用户毫无关系**。

5.   
     系统调用接口`fsync`可以用来同步文件内核状态到存储设备中，即**强制刷新内核缓冲区的数据到磁盘（物理设备）上。**

```c
#include <unistd.h>
int fsync(int fd);
```

6.   **真正意义上的fflush不仅要将数据从用户缓冲区依靠write拷贝到内核缓冲区，还要将数据从内核缓冲区依靠fsync刷新到外设中**。

![用户缓冲区与内核缓冲区联系](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux7/202303112200606.png)

## dup2

















































