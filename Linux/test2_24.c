#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define NUM 100

int main()
{

    char str[NUM + 1];
    memset(str, 0, sizeof(str));
    const char* flag = "|/-\\";
    int i = 0;
    while(i <= NUM)
    {
    	str[i] = '#';
//	\033[背景颜色;字体颜色m你要输出的内容\033[0m")
	printf("[\033[40;33m%-101s\033[0m][%d%%][%c]\r",str, i, flag[i % 4]);
	fflush(stdout);
	i++;
	usleep(200000);
    }

    printf("\n");
    return 0;
}
