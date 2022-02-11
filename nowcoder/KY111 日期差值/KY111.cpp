#include <iostream>
using namespace std;

int Count(int year, int month, int day)
{
    int days[13] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 };
    //计算这是当年第多少天
    int num = days[month - 1] + day;
    //加上前 year 年的天数
    num += 365 * year + year / 4 - year / 4 + year / 400;

    if (year % 4 == 0 && year % 100 != 0 && month > 2)
    {
        num += 1;
    }

    return num;
}

int main()

{

    int year1, month1, day1;
    scanf("%4d%2d%2d", &year1, &month1, &day1);
    int n1 = Count(year1, month1, day1);

    int year2, month2, day2;
    scanf("%4d%2d%2d", &year2, &month2, &day2);
    int n2 = Count(year2, month2, day2);

    cout << abs(n1 - n2) + 1 << endl;
    return 0;
}