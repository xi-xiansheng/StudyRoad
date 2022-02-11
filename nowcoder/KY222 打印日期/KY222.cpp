#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int year, month, data, day;
    month = 1;
    data = 0;
    while (cin >> year >> day)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
        {
            days[2] = 29;
        }
        else
        {
            days[2] = 28;
        }
        data += day;
        while (data > days[month])
        {
            month++;
            day = day - days[month - 1];
            data = day;
        }
        printf("%4d-%02d-%02d\n", year, month, data);

    }

    return 0;
}