[TOC]

------

# 1. Linux 软件包管理器 yum

**前言**
&emsp;&emsp;在Linux下安装软件，有三种方法。

```shell
源码			下载到程序的源代码，并进行编译，得到可执行程序。
rmp包		
yum命令行		全称：Yellowdog Updater Modified，主要应用在Fedora, RedHat, Centos等发行版上。
```

&emsp;&emsp;但是这样太麻烦了，于是有些人把一些常用的软件提前编译好，做成软件包（像windows的 .exe 安装文件一样，各种文件已经编译好，并打了包，哪个文件该放到哪个文件夹，都指定好了，安装非常方便）放在一个服务器上，通过包管理器可以很方便的获取到这个编译好的软件包,，直接进行安装。
&emsp;&emsp;软件包和软件包管理器，就好比 "App" 和 "应用商店" 这样的关系。

**语法**

```shell
yum [options] command [package ...]
```

**作用**

```
安装
解决依赖关系
```

1. **查看软件包**  

    &emsp;&emsp;通过 yum list 命令可以罗列出当前一共有哪些软件包。由于包的数目可能非常之多，这里我们需要使用 grep 命令只
    筛选出我们关注的包。例如:  

    ```shell
    yum list | grep lrzsz
    ```

    &emsp;&emsp;结果如下：

    ```
    lrzsz.x86_64                             0.12.20-36.el7                @base
    ```

    &emsp;&emsp;**注意事项：**

    ![image-20220910140520573](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724445.png)

2. **安装软件**

    **举例：**

    ```shell
    sudo yum install lrzsz
    ```

    yum 会自动找到都有哪些软件包需要下载，不加 -y 参数的时候敲 "y" 确认安装。也可以直接加上 -y 选项。

    **注意事项：**

    - 安装软件时由于需要向系统目录中写入内容， 一般需要 sudo 或者切到 root 账户下才能完成。
    - yum安装软件只能一个装完了再装另一个。 正在yum安装一个软件的过程中，如果再尝试用yum安装另外
        一个软件，yum会报错。

3. **卸载软件**  

    ```shell
    sudo yum remove lrzsz
    ```

4. **补充**
    **常用选项：**

    ```shell
    -h：显示帮助信息； 
    -y：对所有的提问都回答 [yes];
    -c：指定配置文件；
    -q：安静模式；
    -v：详细模式； 
    -d：设置调试等级（0-10）； 
    -e：设置错误等级（0-10）； 
    -R：设置yum处理一个命令的最大等待时间； 
    -C：完全从缓存中运行，而不去下载或者更新任何头文件。
    ```

    **常用命令：**

    ```shell
    install 		安装rpm软件包。
                    全部安装 yum install
                    安装指定的安装包 yum install package
    update 			更新rpm软件包。
    				全部更新 yum update
    				更新制定的程序包 yum update package
    check-update 	检查是否有可用的更新rpm软件包。
    				检查可更新的程序 yum check-update
    remove 			删除制定的rpm软件包。
    				删除程序包 yum remove package
    list 			列出资源库中所有可以安装或更新的rpm包。
                    显示所有已经安装和可以安装的程序包 yum list
                    显示指定package安装包的安装情况 yum list package
                    显示资源库中所有可以更新的rpm包 yum list updates
                    显示已经安装的所有rpm包 yum list installed
                    显示已经安装的，但不包括在资源库中的rpm包 yum list extras
    search 			搜索软件包的信息；
    				搜索匹配package字符的rpm包，包括名称、描述 yum search package
    info 			显示制定的rpm软件包的描述信息和概要信息；
                    显示资源库中所有可以安装或更新的rpm包的信息 yum info
                    显示安装包package的信息 yum info package
                    显示pack开头的所有包的信息 yum info pack*
                    显示资源库中所有可以更新的rpm包的信息 yum info updates
                    显示所有已经安装rpm包的信息 yum info installed
                    显示已经安装的，但不包括在资源库中的rpm包的信息 yum info extras
    clean 			清理yum过期的缓存。
                	清除缓存目录下的软件包 yum: clean packages
                	清除缓存目录下的headers: yum clean headers
                	清除缓存目录下旧的headers: yum clean headers
                	清楚缓存中的所有文件 yum clean all
    shell 			进入yum的shell提示符。
    resolvedep 		显示rpm软件包的依赖关系。
    localinstall 	安装本地的rpm软件包。
    localupdate 	本地的rpm软件包进行更新。
    alias 			列出或创建命令别名。
    autoremove 		删除所有原先因为依赖关系安装的不需要的软件包。
    ```

    **查看 yum 源**
    建议不要轻易修改！！！

    ```shell
    ls /etc/yum.conf
    /etc/yum.conf
    [xcs101@VM-4-6-centos ~]$ vim /etc/yum.conf
    ```

    ![image-20220910144019882](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724448.png)

    **yum 配置**

    修改配置

    ```shell
    vim /etc/yum.repos.d/CentOS-Base.repo
    ```

    当然，我的是没有配置过的。
    ![image-20220910144822727](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724449.png)

    **关于 rzsz**

    这个工具用于 windows 机器和远端的 Linux 机器通过 XShell 传输文件。
    安装完毕之后可以通过拖拽的方式将文件上传过去。
    从客户端上传文件到服务端：
    ```shell
    rz [选项]
    选项说明:
    -+, --append	:将文件内容追加到已存在的同名文件
    -a,--ascii		:以文本方式传输
    -b, --binary	:以二进制方式传输，推荐使用
    --delay-startup N:等待N秒
    -e, --escape	:对所有控制字符转义，建议使用
    -E, --rename	:已存在同名文件则重命名新上传的文件，以点和数字作为后缀
    -p, --protect	:对ZMODEM协议有效，如果目标文件已存在则跳过 -
    -q, --quiet		:安静执行，不输出提示信息
    -v, --verbose	:输出传输过程中的提示信息
    -y, --overwrite	:存在同名文件则替换
    -X, --xmodem	:使用XMODEM协议
    --ymodem		:使用YMODEM协议
    -Z, --zmodem	:使用ZMODEM协议
    --version		:显示版本信息
    --h, --help		:显示帮助信息
    
    ```
    从服务端发送文件到客户端：只能是文件，若为目录（文件夹）需打包后再用

    ```shell
    sz filename
    ```

# 2. Linux编辑器 - vim 使用

关于 vim 的安装及配置，大家可以自行搜索安装。

## 2.1 vim的基本概念

vim 有12种模式，我们只需掌握 **命令模式（command mode）、插入模式（Insert mode）和底行模式（last line mode）**。

**正常/普通/命令模式(Normal mode)**

> 控制屏幕光标的移动，字符、字或行的删除、替换，移动复制某区段及进入Insert mode下，或者到 last line mode

**插入模式(Insert mode)**

> 只有在Insert mode下，才可以做文字输入，按「ESC」键可回到命令行模式。

**底行模式(last line mode)**

> 文件保存或退出，也可以进行文件替换，找字符串，列出行号等操作。 
> 在命令模式下，**shift + :  **即可进入该模式。**注意**：必须是英文的 : 
> 要查看你的所有模式：打开vim，底行模式直接输入: help vim-modes  

## 2.2 vim的基本操作

**进入vim**

```shell
vim 文件名
```

**注：**进入vim之后，是处于[ 正常模式 ]，你要切换到 [ 插入模式 ] 才能够输入文字。  

**[ 正常模式 ] 切换至 [ 插入模式 ]**  

```shell
输入 a	光标向后移动
输入 i	光标不动
输入 o	新起一行
```

**[ 插入模式 ] 切换至 [ 正常模式 ]**  

目前处于[ 插入模式 ]，就只能一直输入文字，如果发现输错了字，想用光标键往回移动，将该字删除。
可以先按一下「ESC」键转到 [ 正常模式 ]再删除文字。当然，也可以直接删除。  

**[ 正常模式 ] 切换至 [ 末行模式 ]**  

「shift + ;」, 其实就是输入「 : 」
**注：**必须是英文输入状态下才可以。  

![image-20220910151244910](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724450.png)

## 2.3 vim 正常模式命令集

**插入模式**

```shell
按「i」	切换进入插入模式「insert mode」，按 “ i ” 进入插入模式后是从光标当前位置开始输入文件；
按「a」	进入插入模式后，是从目前光标所在位置的下一个位置开始输入文字；
按「o」	进入插入模式后，是插入新的一行，从行首开始输入文字。
```

**从插入模式切换为命令模式**

```shell
按「ESC」键。  
```

**光标定位**  

```shell
按「h/j/k/l」:		光标向左/下/上/右移动，亦可以使用箭头移动
按「G」:			移动到文章的最后
按「$」:			移动到光标所在行的“行尾”
按「^」:			移动到光标所在行的“行首”
按「w」:			以单词为单位，光标跳到下个字的开头
按「e」:			以单词为单位，光标跳到下个字的字尾
按「b」:			以单词为单位，光标回到上个字的开头
按「#l」:			光标移到该行的第#个位置，如：5l,56l
按「gg」:			光标定位到文本开始
按「shift」+「g」或「G」: 		光标定位到文本末端
按 n +「shift」+「g」或「G」: 	光标定位到任意一行
按「ctrl」+「b」:	屏幕往“后”移动一页
按「ctrl」+「f」:	屏幕往“前”移动一页
按「ctrl」+「u」:	屏幕往“后”移动半页
按「ctrl」+「d」:	屏幕往“前”移动半页
```

**复制、剪切功能**

```shell
「yw」:		将光标所在之处到字尾的字符复制到缓冲区中。
「#yw」:		复制#个字到缓冲区
「yy」:		复制光标所在行到缓冲区。
「#yy」:		例如，「6yy」表示拷贝从光标所在的该行“往下数”6行文字。
「dd」:		删除（剪切）光标所在行
「#dd」:		从光标所在行开始删除（剪切）#行
「p」:		将缓冲区内的字符贴到光标所在位置。
 n + 「p」:	粘贴 n 次 
```

**注意**：所有与 “y” 有关的复制命令都必须与 “p” 配合才能完成复制与粘贴功能。

**文本修改**

```shell
「r」:						替换光标所在处的字符。
 n +「r」:					替换光标所在处的n个字符。
「shift」+「r」或「R」:		 替换光标所到之处的字符，直到按下「ESC」键为止。
「cw」:						更改光标所在处的字到字尾处
「c#w」:						例如，「c3w」表示更改3个字
「shift」+「~」:				对文本大小写转换
「x」:						每按一次，删除光标所在位置的一个字符
「#x」:						例如，「6x」表示删除光标所在位置的“后面（包含自己在内）”6个字符
「X」:						大写的X，每按一次，删除光标所在位置的“前面”一个字符
「#X」:						例如，「20X」表示删除光标所在位置的“前面”20个字符
```

**其他操作**

```shell
「ctrl」+「g」:			列出光标所在行的行号
「u」:				如果您误执行一个命令，可以马上按下「u」，回到上一个操作。按多次 “u” 可以执行多次恢复。
「ctrl」+「r」: 		撤销的恢复
```

## 2.4 vim 末行模式命令集

在使用末行模式之前，请记住先按「ESC」键确定您已经处于正常模式，再按「：」冒号即可进入末行模式。  

**列出行号**  

```shell
「set nu」: 		输入「set nu」后，会在文件中的每一行前面列出行号。
```

**跳到文件中的某一行**

```shell
「#」:			「#」号表示数字，在冒号后输入一个数字，再按回车键就会跳到该行了。
```

**查找字符**  

```shell
「/关键字」: 先按「/」键，再输入您想寻找的字符，如果第一次找的关键字不是您想要的，可以一直按「n」会往后寻找到您要的关键字为止。
「?关键字」：先按「?」键，再输入您想寻找的字符，如果第一次找的关键字不是您想要的，可以一直按「n」会往前寻找到您要的关键字为止。
```

**退出 vim 及保存文件**  

```shell
q	退出
q!	强制退出
w	保存
w!	强制保存
wq!	强制保存并退出
```

**替换**

```shell
%s/待替换关键字/新文本/g
```

**执行bash命令**

```shell
!bash命令
```

**多屏显示**

```shell
vs 新文件 
```

然后「ctrl」+「w」按两次即可实现文档间切换。

**补充—多行注释**

首先按下[Ctrl] + [V],通过[h / j / k/ l]上下选择指定行，再按下[Shift] + [i]，输入[ //] 后按下 [Esc] 即可实现多行注释。

# 3. Linux编译器 - gcc/g++ 使用

**格式**

```shell
gcc [选项] 要编译的文件 [选项] [目标文件]
```

**语法**

```shell
gcc 		[-c|-S|-E] [-std=standard]
           	[-g] [-pg] [-Olevel]
           	[-Wwarn...] [-Wpedantic]
           	[-Idir...] [-Ldir...]
           	[-Dmacro[=defn]...] [-Umacro]
           	[-foption...] [-mmachine-option...]
           	[-o outfile] [@file] infile...
```

**预处理**  

进行宏替换

>   预处理功能主要包**括宏定义，文件包含，条件编译，去注释等**。
>   预处理指令是以 # 号开头的代码行。

```shell
实例: 
gcc –E test.c –o test.i
选项“-E”,该选项的作用是让 gcc 在预处理结束后停止编译过程。
选项“-o”是指目标文件,“.i”文件为已经过预处理的C原始程序
```

**编译**

生成汇编  

>   在这个阶段中，gcc 首先要检查代码的规范性、是否有语法错误等,以确定代码的实际要做的工作,在检查无误后，gcc 把代码翻译成汇编语言。
>   用户可以使用 “-S” 选项来进行查看,该选项只进行编译而不进行汇编，生成汇编代码。

实例: 

```shell
gcc –S test.i –o test.s  
```

**汇编**  

即生成机器可识别代码。

>   汇编阶段是把编译阶段生成的“.s”文件转成目标文件
>   读者在此可使用选项“-c”就可看到汇编代码已转化为“.o”的二进制目标代码了  

实例: 

```shell
gcc –c test.s –o test.o
```

**链接**

即生成可执行文件或库文件。

在成功编译之后,就进入了链接阶段，形成可执行程序。  

实例: 

```shell
gcc test.o –o test 
```

**ldd**

功能：显示共享库的依赖情况。

语法：

```shell
ldd [-vVdr] program ...
```

**实例**

```shell
[xcs101@VM-4-6-centos dir4]$ ll
total 4
-rw-rw-r-- 1 xcs101 xcs101 122 Sep 10 22:30 test.c
[xcs101@VM-4-6-centos dir4]$ gcc -E test.c -o test.i
[xcs101@VM-4-6-centos dir4]$ gcc -S test.i -o test.s
[xcs101@VM-4-6-centos dir4]$ gcc -c test.s -o test.o
[xcs101@VM-4-6-centos dir4]$ gcc test.o -o test
[xcs101@VM-4-6-centos dir4]$ ll
total 44
-rwxrwxr-x 1 xcs101 xcs101  8400 Sep 10 22:31 test
-rw-rw-r-- 1 xcs101 xcs101   122 Sep 10 22:30 test.c
-rw-rw-r-- 1 xcs101 xcs101 16906 Sep 10 22:30 test.i
-rw-rw-r-- 1 xcs101 xcs101  1488 Sep 10 22:31 test.o
-rw-rw-r-- 1 xcs101 xcs101   436 Sep 10 22:30 test.s
[xcs101@VM-4-6-centos dir4]$ ldd test
	linux-vdso.so.1 =>  (0x00007ffce4145000)
	/$LIB/libonion.so => /lib64/libonion.so (0x00007f5715e9e000)
	libc.so.6 => /lib64/libc.so.6 (0x00007f57159b7000)
	libdl.so.2 => /lib64/libdl.so.2 (0x00007f57157b3000)
	/lib64/ld-linux-x86-64.so.2 (0x00007f5715d85000)
[xcs101@VM-4-6-centos dir4]$ file test
test: ELF 64-bit LSB executable, x86-64, version 1 (SYSV), dynamically linked (uses shared libs), for GNU/Linux 2.6.32, BuildID[sha1]=47029e098e3c6f571c6dcbd4d4b8ec7a615e0ef6, not stripped
[xcs101@VM-4-6-centos dir4]$ 
```

如图所示。

![image-20220910223314036](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724451.png)

这里涉及到**函数库**的概念了，其中函数库一般分为**静态库**和**动态库**两种。  

>   静态库是指编译链接时，把库文件的代码全部加入到可执行文件中，因此生成的文件比较大，但在运行时也就不再需要库文件了。其后缀名一般为 “.a”
>   动态库与之相反，在编译链接时并没有把库文件的代码加入到可执行文件中，而是在程序执行时由运行时链接文件加载库，这样可以节省系统的开销。动态库一般后缀名为 “.so”，如前面所述的 libc.so.6 就是动态库。gcc 在编译时默认使用动态库。完成了链接之后，gcc 就可以生成可执行文件,如下所示。
>   gcc默认生成的二进制程序，是动态链接的，这点可以通过 file 命令验证。  

我们可以使用 -static 选项实现静态链接。对比发现，生成的文件体积相差甚大。

![image-20220910225428163](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724452.png)

部分用户可能会出现下述错误：

```shell
/usr/bin/ld: cannot find -lc
collect2: error: ld returned 1 exit status
```

只需要安装 glibc-static 即可。

```shell
sudo yum install -y glibc-static
```

**gcc 选项**  

```shell
-E 		只激活预处理,这个不生成文件,你需要把它重定向到一个输出文件里面
-S 		编译到汇编语言不进行汇编和链接
-c 		编译到目标代码
-o 		文件输出到文件
-static 此选项对生成的文件采用静态链接
-g 		生成调试信息。GNU 调试器可利用该信息。
-shared 此选项将尽量使用动态库，所以生成文件比较小，但是需要系统由动态库.
-O0
-O1
-O2
-O3		编译器的优化选项的4个级别，-O0表示没有优化,-O1为缺省值，-O3优化级别最高
-w 		不生成任何警告信息。
-Wall 	生成所有警告信息。
```

**g++**

g++ 与 gcc 类似。不过，C++有3个后缀，分别为 **.cc / .cpp / .cxx**    具体可见下图：

![image-20220910230937970](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724453.png)

# 4. Linux调试器 - gdb使用

## 4.1 背景知识

程序的发布方式有两种，debug 模式和 release 模式。

debug 模式是可调式的，release 模式是不可调试的。

Debug 通常称为调试版本，它包含调试信息，并且不作任何优化，便于程序员调试程序。是面向程序员的。

Release 称为发布版本，它往往是进行了各种优化，使得程序在代码大小和运行速度上都是最优的，以便用户很好地使用。是面向用户的。

Linux 中 gcc / g++ 编译程序的时候，默认是动态链接，使用动态库。生成出来的二进制程序，默认是release模式。

要使用 gdb 调试，必须在源代码生成二进制程序的时候，加上 -g 选项，才可以被 gdb 调试。

**readelf**

```shell
readelf <option(s)> elf-file(s)
功能：	显示有关 ELF 文件的信息。
```

选项

```shell
-a 
--all					显示全部信息,等价于 -h -l -S -s -r -d -V -A -I
-h 
--file-header			显示ELF文件开始的文件头信息
-l 
--program-headers
--segments				显示程序头（段头）信息
-S 
--section-headers
--sections				显示节头信息
-g 
--section-groups		显示节组信息
-t 
--section-details		显示节的详细信息
-e 
--headers				显示全部头信息，等价于: -h -l -S
-s 
--syms 
--symbols 				显示符号表节的信息，包含静态符号表（.symtab）和动态符号表（.dynsym）
						如果只关心动态符号表可以直接使用--dyn-syms
						如果符号有相应的版本信息，则会显示该版本信息
						版本字符串显示为符号名称的后缀，并以@字符开头，例如foo@VER_1。 
						在解析未版本化引用的符号时，如果该版本是要使用的默认版本，则将显示为后缀，其后跟两个@字符，例如foo@@VER_2
-n 
--notes 				显示note段/节的信息
-r 
--relocs 				显示可重定位节的信息
-u 
--unwind 				显示unwind节信息
-d 
--dynamic 				显示动态节的信息
-V 
--version-info 			显示版本段的信息 
-A 
--arch-specific 		显示特定结构体系信息
-c 
--archive-index			显示二进制文档的标头部分中包含的文件符号索引信息 
-D 
--use-dynamic 			显示符号时，使用动态节中的符号哈希表，而不是符号表节。显示重定位时，使显示动态重定位而不是静态重定位
-x <number or name>
--hex-dump=<number or name>	
						显示指定节的内容为十六进制字节
-p <number or name>
--string-dump=<number or name>	
						显示指定节的内容为可打印的字符串
-R <number or name>
--relocated-dump=<number or name>	
						显示指定节的内容为十六进制字节，并在显示之前重新定位
 -z
 --decompress			要求被x，R或p选项存储的节在显示之前先解压缩。如果未压缩，则将按原样显示
-w[lLiaprmfFsOoRtUuTgAckK]
--debug-dump[=rawline,=decodedline,=info,=abbrev,=pubnames,=aranges,=macro,=frames,=frames-interp,=str,=str-offsets,=loc,=Ranges,=pubtypes,=trace_info,=trace_abbrev,=trace_aranges,=gdb_index,=addr,=cu_index,=links,=follow-links]
						显示文件中DWARF调试节的内容 
-I 
--histogram 			显示符号表时，显示bucket list长度的柱状图
-W 
--wide 					允许输出宽度超过80个字符显示在一行上
-H 
--help 					显示readelf可理解的命令行选项
-v 
--version 				显示readelf的版本信息
@file 					从<file>中获取命令行选项
```

使用如下

![image-20220912213453756](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724455.png)

## 4.2 使用

```shell
gdb [-help] [-nh] [-nx] [-q] [-batch] [-cd=dir] [-f] [-b bps]
           [-tty=dev] [-s symfile] [-e prog] [-se prog] [-c core] [-p procID]
           [-x cmds] [-d dir] [prog|prog procID|prog core]
```

**选项**

```shell
list／l 行号：			显示binFile源代码，接着上次的位置往下列，每次列10行。
list／l 函数名：			列出某个函数的源代码。
r 或 run：			运行程序。
n 或 next：			单条执行。--类似 Visual Studio 中的F10
s或step：				进入函数调用--类似 Visual Studio 中的F11
break(b) 行号：		在某一行设置断点
break 函数名：			在某个函数开头设置断点
info break ：			查看断点信息。
finish：					执行到当前函数返回，然后挺下来等待命令
print(p)：				打印表达式的值，通过表达式可以修改变量的值或者调用函数p 变量：打印变量值。
set var：				修改变量的值
continue(或c)：			从当前位置开始连续而非单步执行程序
run(或r)：				从开始连续而非单步执行程序--类似 Visual Studio 中的F5
delete breakpoints：		删除所有断点
delete breakpoints n：	删除序号为n的断点
disable breakpoints：	禁用断点
enable breakpoints：		启用断点
info(或i) breakpoints：	参看当前设置了哪些断点
display 变量名：			跟踪查看一个变量，每次停下来都显示它的值
undisplay：				取消对先前设置的那些变量的跟踪
until X行号：				跳至X行
breaktrace(或bt)：		查看各级函数调用及参数（调用堆栈）
info（i) locals：			查看当前栈帧局部变量的值
quit：					退出gdb
```

添加断点，查看断点信息：

![image-20220912224511653](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724456.png)

删除断点，是删除其编号。删除后，新的断点编号是递增的。

![image-20220912225056166](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724457.png)

禁用 / 使能断点  

目的：留下调试痕迹。

![image-20220912225329367](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724458.png)

接下来以该文件内容展示：

```c
#include <stdio.h>

int CumulativeSum(int top)
{
	int sum = 0;
	int i = 0;
	for(; i <= top; i++)
	{
		sum += i;
	}
	return sum;
}

int main()
{
    
	int top;
    //scanf("%d", &top);
    top = 50;
    int ret = CumulativeSum(top);
	printf("%d", ret);
	return 0;
}
```

在第 11 和 20 行设置断点。

![image-20220912231011569](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724459.png)

首先运行，下一步执行第20行。

![image-20220912231211028](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724460.png)

1.   **输入 s**

     ​	此过程类似 Visual Studio 中的 F11，进入函数内部。

     ![image-20220912231347076](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724461.png)

2.   **输入 n**

     此过程类似 Visual Studio 中的 F10，单步执行。对比执行前后 ret 值的变化。

     ![image-20220912231717016](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724462.png)

3.   **调用堆栈 — bt**

     ![image-20220912231929176](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724463.png)

4.   **finish**

     finish 执行到当前函数返回，然后停下来等待命令。注意 ret 值变化。

     ![image-20220912232318984](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724465.png)

5.   **until**

     注：若跳转路径上有断点，会先执行到相应断点处。

     ![image-20220912233801316](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724466.png)

6.   **set var**  

     用来修改变量的值，看似鸡肋，常用于调试由函数/值 引起的代码跳转问题。

     ![image-20220912234011512](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724467.png)

上述是 gdb 一些简单使用场景。

# 5. 自动化构建工具 - make/Makefile

## 5.1 背景  

```shell
一个工程中的源文件不计数，其按类型、功能、模块分别放在若干个目录中，makefile定义了一系列的规则来指定，哪些文件需要先编译，哪些文件需要后编译，哪些文件需要重新编译，甚至于进行更复杂的功能操作。
在Visual Studio 中运行代码，其会自动帮助我们解决上述依赖关系。
makefile 带来的好处就是——“自动化编译”，一旦写好，只需要一个make命令，整个工程完全自动编译，极大的提高了软件开发的效率。
make 是一个命令工具，是一个解释makefile中指令的命令工具，一般来说，大多数的IDE都有这个命令，比如：Delphi的make，Visual C++的nmake，Linux下GNU的make。可见，makefile都成为了一种在工程方面的编译方法。
make 是一条命令，makefile是一个文件，两个搭配使用，完成项目自动化构建。
```

## 5.2 实例代码

makefile 代码：

```shell
test:test.c
	gcc test.c -o test
.PHONY:clean
clean:
	rm -f test
```

test.c 代码：

```c
#include <stdio.h> 
#include <unistd.h>

int main()
{
    printf("你好啊\n");
    fflush(stdout);
    sleep(5);
    return 0;
}
```

当我们输入 make / make clean 时，会自动执行部分代码，并且编译出来的文件也是可执行的。

![image-20220913074653772](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724468.png)

## 5.3 详解

首先我们需要知道的是，make 是一条命令，makefile 是一个文件，该文件包含着 目标文件和原始文件的依赖关系，以及依赖方法。然而光有依赖关系还不够，还得有依赖方法。

**基本语法**

```shell
标的(target):	目标文件1 目标文件2
	gcc	-o	欲创建的可执行文件 目标文件1	目标文件2
```

那个标的 （ target） 就是我们想要创建的信息，而目标文件就是具有相关性的  object files, 那创建可执行文件的语法就是以	**tab**	按键开头的那一行！特别给他留意喔， “命令列必须要以 **tab** 按键作为开头”才行！他的规则基本上是这样的：  

>   在 makefile 当中的 # 代表注解；
>   tab 需要在命令行 (例如 gcc 这个编译器指令) 的第一个字符；
>   标的 (target) 与相依文件(就是目标文件)之间需以 “:” 隔开  

**举例**

张三喊室友带饭。张三给他室友打电话说，“我是张三”，这并不能达到让室友带饭的目的，这句话仅仅确认了其依赖关系。张三接着说，“帮我带一份饭”，这就达到了依赖方法。

![image-20220912235900192](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724469.png)

**原理**

我们将生成过程完整地来看。

```shell
test:test.o                                                                                             	gcc test.o -o test 
test.o:test.s
	gcc -c test.s -o test.o 
test.s:test.i
	gcc -S test.i -o test.s 
test.i:test.c
	gcc -E test.c -o test.i
.PHONY:clean
clean:
	rm -f test
```

运行结果如下：

![image-20220913081343302](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724470.png)

1. make会在当前目录下找名字叫 “Makefile” 或 “makefile” 的文件。

2. 如果找到，它会找文件中的第一个目标文件（target），在上面的例子中，他会找到 “test” 这个文件，并把这个文件作为最终的目标文件。

3. 如果 test 文件不存在，或是 test 所依赖的后面的 test.o 文件的文件修改时间要比 test 这个文件新（可以用 touch 测试），那么，他就会执行后面所定义的命令来生成 test 这个文件。

    结果如下：

    ![image-20220913081538986](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724471.png)

4. 如果hello所依赖的 test.o 文件不存在，那么make会在当前文件中找目标为 test.o 文件的依赖性，如果找到则再根据那一个规则生成test.o 文件。（这有点像一个堆栈的过程）

    删除掉 test.o 文件，测试结果如下：

    ![image-20220913081720890](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724472.png)

    ![image-20220913083135184](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724473.png)

5. 当然，你的文件都是存在的啦，于是make会生成 test.o 文件，然后再用 test.o 文件声明 make 的终极任务，也就是执行文件 test了。

6. 这就是整个make的依赖性，make 会一层又一层地去找文件的依赖关系，直到最终编译出第一个目标文件。

7. 在找寻的过程中，如果出现错误，比如最后被依赖的文件找不到，那么make就会直接退出，并报错，而对于所定义的命令的错误，或是编译不成功，make 根本不理。

8. make只管文件的依赖性，即，如果在我找了依赖关系之后，冒号后面的文件还是不在，那么对不起，我就不工作啦。

**注意**

```shell
test:test.o                                                                                             	gcc test.o -o test 
```

其中， gcc 前面必须为 [ Tab ]键入，不可以是空格 ！！！

**.PHONY**

作用：定义 “ 伪目标 ”，总是可执行的。

make 的目标，仅其**依赖文件更新时间比目标文件新**或者**目标文件不存在**才可以执行。

![image-20220913101202565](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724474.png)

**补充**

可以使用特殊符号代替，效果一致。如下：

```shell
gcc $^ -o $@
```

# 6. Linux 小程序 - 进度条

## 6.1 /r  与 /n 区别

**回车符和换行符区别**

在输入文本时，回车键一敲，就开始了新的一行，这个习惯性用法难免误导人们对 回车符（CR, Carriage Return）'\r' 和 换行符（LF, Linefeed）'\n' 的理解。

在 C/C++ 中原风原味地保留了对换行符的理解，回车符 '\r' 仅表示回到行首，并没有包含换行的动作，换行是由 '\n' 来完成的。

与之类似的转义字符：退格（BS, Backspace）'\b'，顾名思义，这个字符的意义是往前退一格，值得注意的是：退格 '\b' 和回车 '\r' 都只是光标的移动，不会删除前面的文本！

执行下列代码：

```c
printf("abc\r\ncba\rrr\bz\n");
```

结果如下：

```c
abc
rza
```

**解释：**在输出 abc 后 \r 使回车符回到当前行即第一行的行首，但不删除字符，所以第一行最终显示 abc，然后 \n 使光标移到下一行，接着输出 cba，\r 再次让光标回到行首，这次不换行，直接接着输出 rr，这样达到的效果是行首两个字符 cb 被替换为 rr，接着 \b 使光标向前一位，输出 z，这样第二个 r 就被换成了 z，然后换行，最终第二行显示结果就是 rza。

## 6.2 缓冲区概念

首先来看执行下列代码：

```c
#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("你好啊");
	sleep(5);
	return 0;
}
```

你认为结果是什么呢？

![回车换行符测试](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724475.gif)

实际运行中可以发现，“你好啊” 是过了5秒才出现的。如果在“你好啊”后面加上 ’\n’，则会立即出现。那么，当printf 执行完，字符串去哪儿了呢？实际上存在于**缓冲区**中。其本质就是一段内存空间，在合适的时候刷新出去。那么，为什么加不加 ‘\n’效果不一样呢？这就涉及到**刷新策略**。

一般来说，有以下几种刷新策略：

```shell
直接刷新，不缓冲
缓冲区写满，再刷新-全缓冲
碰到 '\n' 就刷新-行刷新
强制刷新
```

基于此，我们可以将代码稍加修改，就可以看到预期效果。

```c
#include <stdio.h>
#include <unistd.h>

int main()
{
	printf("你好啊");
	sleep(5);
    fflush(stdout);
	return 0;
}
```

## 6.3 进度条代码

有了上述理解，我们可以很轻松的写出下列代码：

```c
#include <stdio.h>    
#include <unistd.h>    
#include <string.h>    
    
#define NUM 102    
    
int main()    
{    
    const char* op = "-/\\|";    
    char bar[NUM + 2];    
    memset(bar, 0, sizeof(bar));    
    int count = 0;    
    while(count <= 100)    
    {    
        bar[count] = '#';    
        printf("[%-100s][%d%%][%c]\r", bar, count, op[count % 4]);    
        count++;    
        usleep(100000);    
        fflush(stdout);    
    }    
    printf("\n");                                                                                                                                           
    return 0;    
} 
```

**注意：**

%-100s 用来左对齐。

效果如下：

![进度条](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux3/202209131724476.gif)

# 7. 使用 git 命令行

**安装 git**  

```shell
sudo yum install git
```

**下载项目到本地**  

```shell
git clone [url]
```

**提交1- git add**  

将代码放到刚才下载好的目录中 。

```shell
git add [文件名]
```

**提交2- git commit    **  

提交改动到本地 。

```shell
git commit .
```

最后的 "." 表示当前目录。
提交的时候应该注明提交日志，描述改动的详细内容 ，切不可随意填写。

**提交3 - git push  **  

```shell
git push
```

需要填入用户名密码。同步成功后，刷新仓库页面就能看到代码改动了。

亦可以设置免密提交，大家可以自行搜索。

------

以上就是本次 Linux 诸多基础环境开发工具的简单总结，欢迎各位批评指正！