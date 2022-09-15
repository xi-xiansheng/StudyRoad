



[TOC]

------

# 1. Linux权限的概念

Linux下有两种用户：超级用户（root）、普通用户。 

>超级用户：可以再 Linux 系统下做任何事情，不受限制。
>普通用户：在 Linux 下做有限的事情。
>超级用户的命令提示符是 “#” ，普通用户的命令提示符是 “$” 。 

语法：<font color=#8A2BE2 size=4 > su [user]</font>
功能：切换用户。
例如，要从root用户切换到普通用户user，则使用 su user。 要从普通用户user切换到root用户则使用 su
root（root可以省略），此时系统会提示输入 root 用户的密码。 工作目录不变。

![1662605424293](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224795.png)

**注：**

>adduser可用来建立用户帐号。帐号建好之后，再用passwd设定帐号的密码．而可用userdel删除帐号。使用adduser指令所建立的帐号，实际上是保存在 `/etc/passwd` 文本文件中。

语法：<font color=#8A2BE2 size=4 > adduser [选项] 用户名</font>
功能：用于Linux中创建的新的系统用户。

常用选项：

```
  -b, --base-dir BASE_DIR       新账户的主目录的基目录
  -c, --comment COMMENT         新账户的 GECOS 字段
  -d, --home-dir HOME_DIR       新账户的主目录
  -D, --defaults                显示或更改默认的 adduser 配置
  -e, --expiredate EXPIRE_DATE  新账户的过期日期
  -f, --inactive INACTIVE       新账户的密码不活动期
  -g, --gid GROUP               新账户主组的名称或 ID
  -G, --groups GROUPS   		新账户的附加组列表
  -h, --help                    显示此帮助信息并推出
  -k, --skel SKEL_DIR   		使用此目录作为骨架目录
  -K, --key KEY=VALUE           不使用 /etc/login.defs 中的默认值
  -l, --no-log-init     		不要将此用户添加到最近登录和登录失败数据库
  -m, --create-home     		创建用户的主目录
  -M, --no-create-home          不创建用户的主目录
  -N, --no-user-group   		不创建同名的组
  -o, --non-unique              允许使用重复的 UID 创建用户
  -p, --password PASSWORD       加密后的新账户密码
  -r, --system                  创建一个系统账户
  -R, --root CHROOT_DIR         chroot 到的目录
  -s, --shell SHELL             新账户的登录 shell
  -u, --uid UID                 新账户的用户 ID
  -U, --user-group              创建与用户同名的组
  -Z, --selinux-user SEUSER     为 SELinux 用户映射使用指定 SEUSER
```

语法：<font color=#8A2BE2 size=4 > passwd [选项...] <帐号名称></font>
功能：用于设置用户的认证信息，包括用户密码、账户锁定、密码失效等。直接运行passwd命令修改当前的用户密码，对其他用户的密码操作需要管理员权限。

常用选项：

```
  -k, --keep-tokens       保持身份验证令牌不过期
  -d, --delete            删除已命名帐号的密码(只有根用户才能进行此操作)
  -l, --lock              锁定指名帐户的密码(仅限 root 用户)
  -u, --unlock            解锁指名账户的密码(仅限 root 用户)
  -e, --expire            终止指名帐户的密码(仅限 root 用户)
  -f, --force             强制执行操作
  -x, --maximum=DAYS      密码的最长有效时限(只有根用户才能进行此操作)
  -n, --minimum=DAYS      密码的最短有效时限(只有根用户才能进行此操作)
  -w, --warning=DAYS      在密码过期前多少天开始提醒用户(只有根用户才能进行此操作)
  -i, --inactive=DAYS     当密码过期后经过多少天该帐号会被禁用(只有根用户才能进行此操作)
  -S, --status            报告已命名帐号的密码状态(只有根用户才能进行此操作)
  --stdin                 从标准输入读取令牌(只有根用户才能进行此操作)
```

语法：<font color=#8A2BE2 size=4 > userdel [选项] 用户名</font>

功能：删除用户账户和相关文件。

**注：** 如果有该要删除用户相关的进程正在运行，userdel命令通常不会删除一个用户账号。如果确实必须要删除，可以先终止用户进程，然后再执行userdel命令进行删除。但是userdel命令也提供了一个面对该种情况的参数，即 ”-f” 选项。

常用选项：

```
选项：
  -f, --force                   强制执行一些可能会失败的操作
  -h, --help                    显示此帮助信息并推出
  -r, --remove                  删除主目录和邮件池
  -R, --root CHROOT_DIR         chroot 到的目录
  -Z, --selinux-user            为用户删除所有的 SELinux 用户映射
```

**实例：**

正常登陆的用户，在 /home 下都有家目录，所以可以直接看这个目录下的文件。 

![image-20220908180948229](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224796.png)

# 2. Linux权限管理

文件的权限受到用户及文件属性共同决定。

## 2.1 文件访问者的分类

>u---User      文件和文件目录的所有者
>g---Group   文件和文件目录的所有者所在的组的用户
>o---Others  其它用户

group存在意义：保证项目安全的前提，方便组内协同。默认单人自成组。

## 2.2 文件类型和访问权限

当我们使用 ll 命令时，可以看到如下信息：

![image-20220908210630792](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224797.png)

具体来看，即下述图片所示：

![image-20220908180840402](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224798.png)

**a) 文件类型**  

```
d:	文件夹
-:	普通文件
l:	软链接（类似Windows的快捷方式）
b:	块设备文件（例如硬盘、光驱等）
p:	管道文件
c:	字符设备文件（例如屏幕等串口设备）
s:	套接口文件  
```

![image-20220908223237538](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224799.png) 

**b) 基本权限**  

```
r 	:	Read对文件而言，具有读取文件内容的权限；对目录来说，具有浏览该目录信息的权限
w	:	Write对文件而言，具有修改文件内容的权限；对目录来说具有删除移动目录内文件的权限
x	:	execute对文件而言，具有执行文件的权限；对目录来说，具有进入目录的权限
-	:	表示不具有该项权限
```

## 2.3 权限修改

**a) chmod**  

语法：<font color=#8A2BE2 size=4 > chmod [参数] 权限 文件名  </font>
功能：改变文件的访问权限。
说明：只有文件的拥有者和root才可以改变文件的权限  。

```
-c, --changes				只有在文件的权限确实改变时才进行详细的说明
-f, --silent, --quiet		不输出权限不能改变的文件的错误信息
-v, --verbose              	详细说明权限的变化
-R, --recursive     		改变目录及其所有子目录的文件的权限
--reference=rfile   		(更新在fileutils 4.0上) 改变文件的模式到rfile.
```

**1. 用户符号 +-= 权限字符  :**  

```
+:向权限范围增加权限代号所表示的权限
-:向权限范围取消权限代号所表示的权限
=:向权限范围赋予权限代号所表示的权限
用户符号
u：拥有者
g：拥有者同组用
o：其它用户
a：所有用户
```

**实例：**
![image-20220908213842531](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224800.png)

**2. 三位8进制数字**  

我们将每一位是否具有权限用 0 / 1 表示，则每一组权限可以看成由3个二进制位表示，其范围 0 ~ 7，正好是一个 8 进制的表示范围。则一个8进制数转换成2进制可以表示权限，故3位8进制数可以表示3组权限。
![image-20220908220225636](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224801.png)
故，还有下列写法
![image-20220908220511896](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224802.png)



**b) chown**  

语法：<font color=#8A2BE2 size=4 >chown [ 参数 ] 用户名 文件名   </font>
功能： 修改文件所有者和组别。
选项：

```
-c, --changes
              详尽地描述每个 file 实际改变了哪些所有权.
-f, --silent, --quiet
              不打印文件所有权不能修改的报错信息.
-h, --no-dereference
              只作用于其本身的符号链接,而不修改它们所指向的文件.  这只在提供了 lchown 系统调用的情况下才可用.
-v, --verbose
              详尽地描述对每个 file 所执行的操作(或者无操作).
-R, --recursive
              递归地修改目录及其下面内容的所有权.
--dereference
              修改符号链接目标端的所有权,而非符号链接自身.  (fileutils 4.0中实现的新功能.)
--reference=rfile
              (fileutils 4.0中实现的新功能.)  修改 file 的所有权为 rfile 的所有权.
```

**实例：**

![image-20220908221318176](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224803.png)

**b) chgrp  **  

语法：<font color=#8A2BE2 size=4 >chgrp [ 参数 ] 用户组名 文件名     </font>
功能： 改变文件的组所有权。
选项：

```
-R     递归的改变目录和它的内容的组所有权 (即使遇到错误也继续)
--     结束选项列表.
```

![image-20220908221700573](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224804.png)

另一写法：

![image-20220908221915128](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224805.png)

**补充**

我们取消所有者执行权限，同时又隶属于拥有组，且拥有组由执行权限。但是我们发现，我们并不能执行该 test 文件。原因：默认以拥有者身份执行，非拥有者再判断是否在所属组。

![image-20220908222257182](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224806.png)



**file 指令：**  

语法：<font color=#8A2BE2 size=4 >file [ -bcnsvzL ] [ -f 命名文件 ] [ -m 幻数文件 ] file ...     </font>
功能： 确定文件类型。
选项：

```
-b      不输出文件名 (简要模式).
-c      详细显示指令执行过程，便于排错或分析程序执行的情形。
-m list 指定包含幻数的文件列表.可以是单个文件，也可以是 用冒号分开的多个文件.
-n      每检查完一个文件就强制刷新标准输出. 仅在检查一组文件时才有效.  一般在将文件类型输出到管道时才采用此选项.
-v      打印程序版本并退出.
-z      试图查看压缩文件内部信息.
-L      (在支持符号链接的系统上)选项显示符号链接文件的原文件, 就像 ls(1) 命令的like-named 选项.
```

![image-20220908223940818](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224807.png)

**umask掩码**
>一般普通文件，起始权限666
>一般普通目录，起始权限777

然而，我们看到的是775， 664

![image-20220908224552149](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224808.png)

查看umask

![image-20220908224649698](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224809.png)

```
取后三位，则002，转为2进制，即 000 000 010
进行 default & ~umask
```

![image-20220908225331947](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224810.png)

![image-20220908225453392](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224811.png)

也就是说，凡是在umask出现的权限，都不该在最终权限出现。

**面试题**

```
在目录下创建文件，需要什么权限？  
查看目录下文件列表需要什么权限？ 
进入目录需要什么权限？
```

前两个一下就回答出来了，看第三个问题。

![image-20220908231231703](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224812.png)

实验可得，需要 执行权限！

**粘滞位**  

先来看一个实验：

![image-20220909010715680](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224813.png)

如图所示，我们更改了 rmo.txt 的所有者，所属组，other的写和执行权限。但是我们依旧可以将其删除。

接下来，我们使用 root 创建新目录 dir，file.txt 文件并修改相关权限。删除 各 file.txt 文件，仅删除掉 file4.txt 文件。即便在上级目录也无法删掉。

![image-20220909120734349](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224814.png)

接下来，将 dir目录清空，更改为普通用户，删除 dir 目录。可以发现，此时是可以删除掉的。

![image-20220909121649931](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux2/202209091224815.png)

# 3. 总结

```
1. 	目录的可执行权限是表示你可否在目录下执行命令。
2. 	如果目录没有-x权限，则无法对目录执行任何命令，甚至无法cd 进入目, 即使目录仍然有-r 读权限。
3. 	如果目录具有-x权限，但没有-r权限，则用户可以执行命令，可以cd进入目录。
	但由于没有目录的读权限所以在目录下，即使可以执行ls命令，但仍然没有权限读出目录下的文档。
```

------

以上就是本次 Linux 权限的简单总结，欢迎各位批评指正！
