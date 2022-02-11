#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    int n;
    cin >> n;
    while (n--)
    {
        int year, month, data, day;
        cin >> year >> month >> data >> day;
        while (day)
        {
            if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            {
                days[2] = 29;
            }
            else
            {
                days[2] = 28;
            }
            if (day + data > days[month])
            {
                day = day - days[month] + data - 1;
                month++;
                year += month / 13;
                month = (month - 1) % 12 + 1;
                data = 1;
            }
            else
            {
                data += day;
                day = 0;
            }
        }
        printf("%4d-%02d-%02d\n", year, month, data);

    }

    return 0;
}




