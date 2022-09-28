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
    printf("%d\n", ret);
    return 0;
}
