[TOC]

<hr style=" border:solid; eight:1px;" color=#000000 size=1">


# 1.ls 指令

语法：<font color=#8A2BE2 size=4 > ls [选项]  [目录或文件]</font>
功能：

> 对于目录，该命令列出该目录下的所有子目录与文件。
>
> 对于文件，将列出文件名以及其他信息。



常用选项： 

|常用选项|                             功能                           |
| :------: | :----------------------------------------------------------: |
|    -a    |       列出目录下的所有文件，包括以 . 开头的隐含文件。        |
|    -d    | 将目录像文件一样显示，而不是显示其下的文件。 如： ls –d 指定目录 |
|    -i    |       输出文件的 i 节点的索引信息。 如 ls –ai 指定文件       |
|    -k    |      以 k 字节的形式表示文件的大小。如 ls –alk 指定文件      |
|    -l    |                     列出文件的详细信息。                     |
|    -n    |                 用数字的 UID,GID 代替名称。                  |
|    -F    | 在每个文件名后附上一个字符以说明该文件的类型。 “*”表示可执行的普通文件； “/”表示目录； “@”表 示符号链接；“\|” 表示FIFOs； “=”表示套接字(sockets)。（目录类型识别） |
|    -r    |                       对目录反向排序。                       |
|    -t    |                       以时间顺序排序。                       |
|    -s    | 在l文件名后输出该文件的大小。（大小排序，如何找到目录下最大的文件） |
|    -R    |                递归式列出所有子目录下的文件。                |
|    -1    |                     一行只输出一个文件。                     |

**例：**

<font color=#FF00FF size=4 >ls -a </font>

如下图，当处于同一路径下，-a 选项可以显示隐藏文件。其中，在Linux下，隐藏文件均以 .开头。

![1662448145399](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048168.png)

<font color=#FF00FF size=4 >ls -l </font>

如下图，对比发现，仅使用 ls 指令，仅显示已有非隐藏文件，加上 -l 选项后， 每个文件前出现了其信息。

![1662448885482](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048169.png)

<font color=#FF00FF size=4 >ls -nl</font>

如图可见，两列信息发生变化，由 root 变为 0 。具体信息可参考下一文章。

![](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048170.png)

<font color=#FF00FF size=4 >ls -F</font>

对比是否加 -F 选项，我们可以看到每个文件后面出现了不同的符号， 表示不同的文件类型。

![](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048171.png)



# 2.pwd命令

语法: <font color=#8A2BE2 size=4 > pwd </font>

功能：显示用户当前所在的目录 

常用选项：无

**使用如下**：

![1662448422249](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048172.png)



**注：** ‘/’ 表示路径分隔符，首位 ‘/’ 表示当前用户所处的家目录

# 3.cd 指令

语法: <font color=#8A2BE2 size=4 > cd  [目录名]</font>

功能：改变工作目录。将当前工作目录改变到指定的目录下。

举例：

> cd .. : 返回上级目录
> cd /home/xcs101/linux/ : 绝对路径
> cd ../dir2/ : 相对路径
> cd ~：进入用户家目
> cd -：返回最近访问目录 



<font size = 4 color=#000000>说明1：</font>

我们任意访问某一目录，以dir3为例，我们可以看到如下文件。

![1662450324629](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048173.png)

几乎任一目录下， 均含有 .  和 .. 文件，且其属性为目录。其中， . 表示当前路径， ..表示上级路径。方便命令行回退到上级目录与后续运行程序。

![1662450450366](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048174.png)

<font size = 4 color=#000000>说明2：</font>

绝对路径：绝对路径是指文件所处真正存在的路径。 路径下的文件可以一直找到，例如 /home/dir/

相对路径：相对于自己的目标文件位置。例如  ../etc/test.c

其中，路径标识（唯一）一个文件。因为每个文件的路径唯一。

![1662451889645](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048175.png)

<font size = 4 color=#000000>说明3：</font>

<font color=#8A2BE2 size=4 > cd  ~</font>  

在Linux 下，我们可能有不同的身份，比如 root 用户或 普通用户，而<font color=#8A2BE2 size=4 > cd  ~</font> 代表着 进入当前用户的家目录，即默认登陆时所处的目录。

![1662452309789](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048176.png)

# 4.touch 指令

语法: <font color=#8A2BE2 size=4 > touch [选项] [文件] </font>

功能： touch命令参数可更改文档或目录的日期时间，包括存取时间和更改时间，或者新建一个不存在的文件。

| 选项 | 功能  |
| :--: | :--: |
|  -a  | 或--time=atime或--time=access或--time=use只更改存取时间。 |
|  -c  | 或--no-create 不建立任何文档。 |
|  -d  | 使用指定的日期时间，而非现在的时间。可以使用各种不同的格式。 |
|   -f   | 此参数将忽略不予处理，仅负责解决BSD版本touch指令的兼容性问题。 |
|    -m  | 或--time=mtime或--time=modify 只更改变动时间。 |
|    -r  | 把指定文档或目录的日期时间，统统设成和参考文档或目录的日期时间相同。 |
| -t | 使用指定的日期时间，而非现在的时间。 |

<font color=#00FF00 size=4 > stat </font> 可用来查看文件属性

> Access: 文件访问时间
>
> Modify: 内容修改时间
>
> Change: 属性修改时间

![1662453088047](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048177.png)

&emsp;&emsp;使用touch命令，如果文件存在则更新<font color=#FF00FF size=3 > Access,Modify,Change </font>为当前时间。

![1662453777220](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048178.png)

&emsp;&emsp;&emsp;使用 -a 参数，touch文件时，文件存在只会更新<font color=#FF00FF size=3 > Access,Change </font>为当前时间。

![1662453865490](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048179.png)

&emsp;使用-m参数，touch文件时，文件存在只会更新<font color=#FF00FF size=3 > Modify,Change </font>为当前时间。

![1662453958193](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048180.png)

&emsp;-d 与 -t 参数的作用相同，指定文件 <font color=#FF00FF size=3 > Access,Modify </font>，只是使用格式略有区别，使用字符串形式来指定时间：

&emsp;使用touch -d "1 years ago" [文件] 可以将文件的<font color=#FF00FF size=3 > Access,Modify</font>改为1年前。

![1662454138844](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048181.png)

&emsp;-t 参数：指定文件<font color=#FF00FF size=3 > Access,Modify</font>，可以使用 1970年1月1日到指定日期的毫秒数，也可以直接使用日期，格式为 [[CC]YY]MMDDhhmm[.ss]：

![1662454383428](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048182.png)

&emsp;如果只想更新<font color=#FF00FF size=3 > Access </font>可以使用 -at 组合参数。

![1662454580025](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048183.png)

&emsp;如果只想更新<font color=#FF00FF size=3 > Modify </font>可以使用 -mt 组合参数。

**注：**touch 没有相关参数来指定文件 ctime，即新创建的文件的 ctime 只能为当前时间。

# 5.mkdir指令 && tree 命令

语法： <font color=#8A2BE2 size=4 > mkdir [选项] dirname... </font>
功能：在当前目录下创建一个名为  “dirname” 的目录 

|   常用选项    |                             功能                             |
| :-----------: | :----------------------------------------------------------: |
| -p, --parents | 可以是一个路径名称。此时若路径中的某些目录尚不存在,加上此选项后,系统将自动建立好那些尚不存在的目录,即一次可以建立多个目录; |

![1662454930240](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048184.png)



语法： <font color=#8A2BE2 size=4 > tree [选项] [目录] </font>
功能：用于以树状图列出目录的内容

安装： 

```
sudo yum install tree
```



| 常用选项 |                             功能                             |
| :------: | :----------------------------------------------------------: |
|    -a    |             显示所有文件和目录（包括隐藏文件）。             |
|    -A    | 使用ASNI绘图字符显示树状图而非以ASCII字符组合（不包括隐藏文件）。 |
|    -C    |                  在文件和目录清单加上色彩。                  |
|    -d    |                         仅显示目录。                         |
|    -D    |                  列出文件或目录的更改时间。                  |
|    -f    |        在每个文件或目录之前，显示完整的相对路径名称。        |
|    -F    |        在每个文件名后附上一个字符以说明该文件的类型。        |
|    -g    | 列出文件或目录的所属群组名称，没有对应的名称时，则显示群组识别码。 |
|    -i    |                不以阶梯状列出文件或目录名称。                |
|    -L    |                 即level，限制目录显示层级。                  |
|    -I    | 如遇到性质为符号连接的目录，直接列出该连接所指向的原始目录。 |
|    -n    |                 不在文件和目录清单加上色彩。                 |
|    -N    |            直接列出文件和目录名称，包括控制字符。            |
| -p(小写) |                        列出权限标示。                        |
| -P(大写) |             只显示符合范本样式的文件或目录名称。             |
|    -q    |         用 "?" 号取代控制字符，列出文件和目录名称。          |
|    -s    |                     列出文件或目录大小。                     |
|    -t    |                 用文件和目录的更改时间排序。                 |
|    -u    | 列出文件或目录的拥有者名称，没有对应的名称时，则显示用户识别码。 |

效果展示：

![1662469187166](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048185.png)

# 6.rmdir指令 && rm 指令

语法： <font color=#8A2BE2 size=4 > rmdir </font>
功能：删除空目录

语法： <font color=#8A2BE2 size=4 > rm [选项] [目录/文件]</font>
功能：删除文件或目录 

| 常用选项 |           功能           |
| :------: | :----------------------: |
|    -r    | 递归删除其子目录及文件。 |
|    -f    |        强制删除。        |
|    -i    |   删除前逐一询问确认。   |

# 7.man指令

语法： <font color=#8A2BE2 size=4 > man [选项1] [选项2] [指令/命令]</font>

| 常用选项1 |                             功能                             |
| :-------: | :----------------------------------------------------------: |
|    -k     |                   根据关键字搜索联机帮助。                   |
|    num    |                      只在第num章节找。                       |
|    -a     | 将所有章节的都显示出来,当按下q退出，他会继续往后面搜索，直到所有章节都搜索完毕。 |

| 选项2 |                    功能                    |
| :---: | :----------------------------------------: |
|   1   |                普通的命令。                |
|   2   |               系统调用命令。               |
|   3   |             各种库的特殊函数。             |
|   4   |   特殊文件，也就是/dev下的各种设备文件。   |
|   5   |               指文件的格式。               |
|   6   |      给游戏留的，由各个游戏自己定义。      |
|   7   |             附件还有一些变量。             |
|   8   | 系统管理用的命令，这些命令只能由root使用。 |

例如：man man 可以将 man 的所有选项及其含义显示出来。

![1662467823431](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048186.png)

# 8.cp指令

语法： <font color=#8A2BE2 size=4 > cp [选项] 源文件或目录 目标文件或目录 </font>

功能:   复制文件或目录
说明:  cp指令用于复制文件或目录，如同时指定两个以上的文件或目录，且最后的目的地是一个已经存在的目录，
则它会把前面指定的所有文件或目录复制到此目录中。若同时指定多个文件或目录，而最后的目的地并非一个已存
在的目录，则会出现错误信息 

|      常用选项       |                             功能                             |
| :-----------------: | :----------------------------------------------------------: |
|    -f 或 --force    |    强行复制文件或目录， 不论目的文件或目录是否已经存在。     |
| -i 或 --interactive |                    覆盖文件之前先询问用户                    |
|         -r          | 递归处理，将指定目录下的文件与子目录一并处理。若源文件或目录的形态，不属于目录或符号链接，则一律视为普通文件处理 |
|  -R 或 --recursive  |         递归处理，将指定目录下的文件及子目录一并处理         |

# 9.mv指令 

语法： <font color=#8A2BE2 size=4 > mv [选项] 源文件或目录 目标文件或目录  </font>

功能:

>1. 视 mv 命令中第二个参数类型的不同（是目标文件还是目标目录），mv命令将文件重命名或将其移至一个新的目录中。
>
>2. 当第二个参数类型是<font color=#32CD32 size=3 >「文件」</font>文件时， mv命令完成文件<font color=#32CD32 size=3 >「重命名」</font>，此时，源文件只能有一个（也可以是源目录名），它将所给的源文件或目录重命名为给定的目标文件名。
>
>3. 当第二个参数是已存在的目录名称时，源文件或目录参数可以有多个， mv命令将各参数指定的源文件均移至目标目录中。 即实现<font color=#32CD32 size=3 >「剪切」</font> 功能。



| 常用选项 |                             功能                             |
| :------: | :----------------------------------------------------------: |
|    -f    | force 强制的意思，如果目标文件已经存在，不会询问而直接覆盖。 |
|    -i    |   若目标文件 (destination) 已经存在时，就会询问是否覆盖。    |

# 10.cat指令

语法： <font color=#8A2BE2 size=4 > cat [选项] [文件]   </font>

功能： 完整查看目标文件的内容

| 常用选项 | 功能 |
| :------: | :----------------: |
|    -b    |  对非空输出行编号  |
|    -n    |显示行号。|
|    -s    |   不输出多行空行   |



补充：还有一个命令为 <font color=#8A2BE2 size=4 > tac </font>, 与 cat 作用一致，不过是自下而上打印。一次输出所有内容，故其与 cat 适合较小文件。

# 11.more指令 

语法： <font color=#8A2BE2 size=4 > more [选项] [文件]  </font>

功能： 与 cat 类似，不过适合大文件，仅能向后移动。

| 常用选项 |        功能        |
| :------: | :----------------: |
| -number  | 指定显示前number列 |
|    q     |      退出more      |

# 12.less指令 

语法： <font color=#8A2BE2 size=4 > less [参数] 文件   </font>

功能： less 与 more 类似，但使用less可以随意浏览文件，而且less在查看之前不会加载整个文件。

 

| 常用选项 |                  功能                  |
| :------: | :------------------------------------: |
|    -i    |          忽略搜索时的大小写。          |
|    -N    |            显示每行的行号。            |
| /字符串  |          向下搜索 “字符串” 。          |
| ?字符串  |          向上搜索 “字符串”。           |
|    n     |   重复前一个搜索（与 / 或 ? 有关）。   |
|    N     | 反向重复前一个搜索（与 / 或 ? 有关）。 |
|    q     |退出less                   |

# 13.head指令 

语法： <font color=#8A2BE2 size=4 > head [参数]  [文件]    </font>

功能： head 用来显示档案的开头至标准输出中，默认head命令打印其相应文件的开头10行。 

| 常用选项 |    功能    |
| :------: | :--------: |
|    n     | 显示的行数 |



# 14.tail指令 


语法： <font color=#8A2BE2 size=4 >tail  [必要参数] [选择参数] [文件]   </font>

功能： 用于显示指定文件末尾内容，不指定文件时，作为输入信息进行处理。常用查看日志文件。 

| 常用选项 |    功能    |
| :------: | :--------: |
|    n     | 显示的行数 |
|    f     |  循环读取  |

**11 - 14 补充**

&emsp;&emsp;此处为补充知识，仅简单说明。

命令： echo

> 语法： <font color=#8A2BE2 size=4 >echo  [参数] [字符串]  </font>
>
> 功能：将字符串回显到标准输出。

**重定向**

&emsp;&emsp;重定向分为 <font color=#8A2BE2 size=3 >「输出重定向」</font>和  <font color=#8A2BE2 size=3 >「输入重定向」</font> 

|   命令符号    |                             说明                             |
| :-----------: | :----------------------------------------------------------: |
| cmd << 标识符 | 使用此命令符是需用键盘输入内容，(标准输入，标识符可以自定义)。 |
|  cmd < 文件   |           将指定文件中的内容作为输入(非标准输入)。           |
|  cmd >> 文件  |                将命令的结果追加到指定的文件。                |
|  cmd > 文件   |                将命令的结果覆盖到指定的文件。                |

```
echo "你好啊"
```

当前命令仅输出到屏幕上。

```
echo "你好啊" >> test.txt
```

打开已有文件 test.txt ，将 ”你好啊“ 追加到 test.txt 文件中

结果如下图：

![1662540372585](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048187.png)

<< 配合 cat 的使用

![1662541109370](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048188.png)



**管道**

> | 表示管道，上一条命令的输出，作为下一条命令参数(输入)。



**例** ： 逆序打印 hello.txt 的中间 10 行

```
count=0; while [ $count -le 10000 ]; do echo "hello $count"; let count++; done > hello.txt
```

使用该命令创建10000行数据。

![1662541888430](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048189.png)

# 15.时间相关的指令

date显示 
语法： <font color=#8A2BE2 size=4 >date [OPTION]...  [+FORMAT]  </font>

1. **显示**

    date 指定格式显示时间： date +%Y:%m:%d

    可以自定义显示格式，格式设定为一个加号后接数个标记，其中常用的标记列表如下 ：

    | 参数 |          说明          |
    | :--: | :--------------------: |
    |  %H  |     小时(00 - 23)      |
    |  %M  |     分钟(00 - 59)      |
    |  %S  |      秒(00 - 59)       |
    |  %X  |    相当于 %H:%M:%S     |
    |  %d  |      日 (01 - 31)      |
    |  %m  |     月份 (01 - 12)     |
    |  %Y  | 完整年份 (0000 - 9999) |
    |  %F  |    相当于 %Y-%m-%d     |

2. **设定**

|             格式              |                            说明                             |
| :---------------------------: | :---------------------------------------------------------: |
|            date -s            |     设置当前时间，只有root权限才能设置，其他只能查看。      |
|       date -s 20080523        | 设置成 2008 05 23，这样会把具体时间设置成空，即 00:00:00 。 |
|       date -s 01:01:01        |              设置具体时间，不会对日期做更改。               |
| date -s “01:01:01 2008-05-23″ |                       设置全部时间。                        |
|  date -s “01:01:01 20080523″  |                       设置全部时间。                        |
| date -s “2008-05-23 01:01:01″ |                       设置全部时间。                        |
|  date -s “20080523 01:01:01″  |                       设置全部时间。                        |

3. **时间戳** 

Unix时间戳（英文为Unix epoch, Unix time, POSIX time 或 Unix timestamp）是从1970年1月1日（UTC/GMT的
午夜）开始所经过的秒数，不考虑闰秒。

时间->时间戳： date +%s
时间戳->时间： date -d@秒数
 ![1662544567482](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048190.png)

# 16.cal指令

语法： <font color=#8A2BE2 size=4 >cal [参数] [月份] [年份] </font>

功能： 用于查看日历等时间信息，如只有一个参数，则表示年份(1-9999)，如有两个参数，则表示月份和年份 。

| 常用选项 |                             功能                             |
| :------: | :----------------------------------------------------------: |
|    -3    |          显示系统前一个月，当前月，下一个月的月历。          |
|    -j    | 显示在当年中的第几天（一年日期按天算，从1月1号算起，默认显示当前月在一年中的天数）。 |
|    -y    |                     显示当前年份的日历。                     |

# 17.find指令

语法： <font color=#8A2BE2 size=4 >find pathname -options </font>

功能： 用于在文件树种查找文件，并作出相应的处理（可能访问磁盘） 。

| 常用选项 |         功能         |
| :------: | :------------------: |
|  -name   | 按照文件名查找文件。 |

**补充：**

**which**

功能：专门查找命令所在路径的命令。

**whereis**

功能：在系统特定路径下，进行文档、命令等相关文件的查找。

![1662545587017](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048191.png)

**alias**

语法： <font color=#8A2BE2 size=4 >alias [-p]  [name [=value] ...]</font>

功能：用来设置指令的别名。

>- -p：显示全部已定义的别名。
>
>- name（可选）：指定要（定义、修改、显示）的别名。
>- value（可选）：别名的值。

![1662546026565](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048192.png)

常见的 ll 其实就是 ls -l 的别名

![1662546099832](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048193.png)

取消别名，只需要退出当前终端即可。亦可以设置路径永久保存别名。

# 18.grep指令

语法： <font color=#8A2BE2 size=4 >grep [选项] [--color=auto] 搜寻字符串 文件 </font>

功能： 文本 行过滤工具。在文件中搜索字符串，将找到的行打印出来。

|   常用选项   |                         功能                         |
| :----------: | :--------------------------------------------------: |
|      -i      |        忽略大小写的不同，所以大小写视为相同。        |
|      -n      |                    顺便输出行号。                    |
|      -v      | 反向选择，亦即显示出没有 '搜寻字符串' 内容的那一行。 |
|      -E      |                   可以用来扩展选项为正则表达式。 如果使用了grep 命令的选项-E，则应该使用|来分割多个pattern，以此实现OR操作。                                   |
|      -c      |            计算找到 '搜寻字符串' 的次数。            |
|      -a      |      将 binary 文件以 text 文件的方式搜寻数据。      |
| --color=auto |        可以将找到的关键词部分加上颜色的显示。        |

**补充**

命令： dmesg

> 功能： 打印内核环形缓冲区。

![1662559895987](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048194.png)

# 19.zip/unzip指令

语法： <font color=#8A2BE2 size=4 >zip 压缩文件.zip 目录或文件 </font>

功能： zip 压缩文件.zip 目录或文件。

| 常用选项 |                        功能                        |
| :------: | :------------------------------------------------: |
|    -r    | 递归处理，将指定目录下的所有文件和子目录一并处理。 |



![1662560687711](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048195.png)

# 20.tar指令

语法： <font color=#8A2BE2 size=4 >tar [参数] 文件与目录 ....&#x2028; </font>

功能： 打包 / 解包，不打开它，直接看内容 。

| 常用选项 |                          功能                          |
| :------: | :----------------------------------------------------: |
|    -c    |      建立一个压缩文件的参数指令(create 的意思)。       |
|    -x    |              解开一个压缩文件的参数指令。              |
|    -t    |               查看 tarfile 里面的文件。                |
|    -z    |  是否同时具有 gzip 的属性？亦即是否需要用 gzip 压缩？  |
|    -j    | 是否同时具有 bzip2 的属性？亦即是否需要用 bzip2 压缩？ |
|    -v    |  压缩的过程中显示文件。常用但不建议用在背景执行过程。  |
|    -f    |    使用档名。在 f 之后要立即接档名。不要再加参数。     |
|    -C    |                    解压到指定目录。                    |

**使用示例**

![1662561674538](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048196.png)

# 21.bc指令

语法： <font color=#8A2BE2 size=4 >bc [-hlwsqv] [long-options] [file...]</font>

功能：可以很方便的进行浮点运算 

安装： 

```
yum install -y bc
```

|       选项        |               说明               |
| :---------------: | :------------------------------: |
|    -h, --help     |       显示帮助信息并退出。       |
| -i, --interactive |       强制进入交互式模式。       |
|   -l, --mathlib   |      定义使用的标准数学库。      |
|    -w, --warn     | 对 POSIX bc 的扩展给出警告信息。 |
|  -s, --standard   | 完全使用 POSIX 版本的 bc 功能。  |
|    -q, --quiet    |  不打印正常的 GNU bc 环境信息。  |
|   -v, --version   |    打印 bc 版本与版权后退出。    |

| 特殊变量 |                       说明                       |
| :------: | :----------------------------------------------: |
|  scale   | 定义某些操作如何使用小数点后的数字，默认值为 0。 |
|  ibase   |        定义输入数的基数，默认为十进制数。        |
|  obase   |        定义输出数的基数，默认为十进制数。        |
|   last   |                表示最后的输出值。                |

**注：**

> bc 中的块注释使用`/* */`，行注释使用 #
>
> bc 中可以使用函数，表达式
>
> bc 的语句使用分号和换行符进行分隔

具体详细用法不过多介绍。

**小部分使用示例如下：**

![1662563208215](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048197.png)

# 22.uname指令 

语法： <font color=#8A2BE2 size=4 >uname [选项] </font>

功能： uname用来获取电脑和操作系统的相关信息。
补充说明： uname可显示linux主机所用的操作系统的版本、硬件的名称等基本信息。 

|          选项           |                             功能                             |
| :---------------------: | :----------------------------------------------------------: |
|        -a, --all        | 详细输出所有信息，依次为内核名称，主机名，内核版本号，内核版本，硬件名，处理器类型，硬件平台类型，操作系统名称。 |
|    -s, --kernel-name    |                        输出内核名称。                        |
|     -n, --nodename      |                   输出网络节点上的主机名。                   |
|  -r, --kernel-release   |                       输出内核发行号。                       |
|  -v, --kernel-version   |                        输出内核版本。                        |
|      -m, --machine      |                   输出主机的硬件架构名称。                   |
|     -p, --processor     |                 输出处理器类型或"unknown"。                  |
| -i, --hardware-platform |                 输出处理器类型或"unknown"。                  |
| -o, --operating-system  |                 输出处理器类型或"unknown"。                  |

**注：** hostname 亦可以用来查询主机名。

![1662564010436](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048198.png)

# 23.热键

语法： <font color=#8A2BE2 size=4 >[Ctrl] c</font>

功能：让当前的程序『停掉』 。

以下列代码为实验：

```
[xcs101@VM-4-6-centos dir3]$ cat test.c
#include <stdio.h>

int main()
{
    while(1)
    {
       printf("你好啊\n");
    }
    return 0;
}
[xcs101@VM-4-6-centos dir3]$ gcc test.c -o test
[xcs101@VM-4-6-centos dir3]$ ./test
```

可以看出，这是一个简单的死循环程序，同时按住 <font color=#8A2BE2 size=4 >[Ctrl] c</font> 即可终止该程序。

![1662598775761](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048199.png)

语法： <font color=#8A2BE2 size=4 >[ Tab ]</font>

功能：具有『命令补全』和『档案补齐』。

使用：输入命令前缀，双击 <font color=#8A2BE2 size=4 >[ Tab ]</font>键，显示其所有命令，过多则提示。若仅有其一个命令，则自动补全。

![1662599013317](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048200.png)

语法： <font color=#8A2BE2 size=4 >history [ 选项 ] [ 参数 ]</font>

功能：

> 1. 用于显示历史记录和执行过的指令命令 
>
> 2. 当登录shell或者是退出的时候会自动进行读取和存储

| 参数 |                         功能                         |
| :--: | :--------------------------------------------------: |
| num  |               显示最近的 num 条记录。                |
|  -a  |       将历史命令缓冲区中命令写入历史命令文件中       |
|  -c  | 将目前的shell中的所有 history 内容全部消除(假删除)。 |
|  -r  |     将目前的shell中的所有 history 内容全部消除。     |
|  -w  |     将目前的shell中的所有 history 内容全部消除。     |
|  -d  |               删除历史记录中指定的行。               |

语法： <font color=#8A2BE2 size=4 >[ Ctrl ] R</font>

功能：反向查找 / 搜索历史命令

同时按下<font color=#8A2BE2 size=4 > [ Ctrl ] R</font> 进入反向搜索状态。

![1662600029225](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048201.png)

继续按住<font color=#8A2BE2 size=4 > [ Ctrl ] R</font>，可以继续向前搜索匹配命令，按住 $$\leftarrow$$ 或 $$\rightarrow$$ 选中

![1662600209257](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048202.png)

语法： <font color=#8A2BE2 size=4 >exit [ 状态值 ]</font>

功能：exit命令用来退出当前用户的shell或退出终端 ，并返回给定值。

![1662601088498](https://xcs-md-images.oss-cn-nanjing.aliyuncs.com/Linux/Linux1/202209082048203.png)

语法： <font color=#8A2BE2 size=4 >logout [ N ]</font>

功能：以状态 N 退出一个登录 shell。同exit 。

语法： <font color=#8A2BE2 size=4 >[ Ctrl ] D</font>

功能：删除提示符后一个字符或 exit 或 logout 。

# 24.关机

语法： <font color=#8A2BE2 size=4 >shutdown [选项] ** </font>

| 常用选项 |                功能                 |
| :------: | :---------------------------------: |
|    -h    |   将系统的服务停掉后，立即关机。    |
|    -r    | 在将系统的服务停掉之后就重新启动。  |
|  -t sec  | -t 后面加秒数，即『过几秒后关机』。 |

# 25.扩展命令

```
◆ 安装和登录命令： login、 shutdown、 halt、 reboot、 install、 mount、 umount、 chsh、 exit、 last
◆ 文件处理命令： file、 mkdir、 grep、 dd、 find、 mv、 ls、 diff、 cat、 ln
◆ 系统管理相关命令： df、 top、 free、 quota、 at、 lp、 adduser、 groupadd、 kill、 crontab
◆ 网络操作命令： ifconfig、 ip、 ping、 netstat、 telnet、 ftp、 route、 rlogin、 rcp、 finger、 mail、 nslookup
◆ 系统安全相关命令： passwd、 su、 umask、 chgrp、 chmod、 chown、 chattr、 sudo ps、 who
◆ 其它命令： tar、 unzip、 gunzip、 unarj、 mtools、 man、 unendcode、 uudecode 
```

<hr style=" border:solid; eight:1px;" color=#000000 size=1">

&emsp;&emsp;以上就是本次Linux 基础指令的简单总结，欢迎各位批评指正！

