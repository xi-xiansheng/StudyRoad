class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return int整型
     */
    int StrToInt(string s) {
        // write code here
        int number = 0;
        int flag = 1;
        int index = 0;
        while (s[index] == ' ')
        {
            index++;
        }
        if (s[index] == '-')
        {
            flag = -1;
            index++;
        }
        else if (s[index] == '+')
            index++;
        else if (s[index] >= '0' && s[index] <= '9')
        {
            ;
        }
        else
        {
            return number;
        }
        while (index < s.size())
        {
            if (s[index] >= '0' && s[index] <= '9')
            {
                long long tmp = (long long)number * 10 + flag * (s[index] - '0');
                if (number < 0 && tmp <= (1 << 31))
                {
                    return 1 << 31;
                }
                else if (number > 0 && tmp >= 0x7fffffff)
                    return 0x7fffffff;
                number = 10 * number + flag * (s[index] - '0');
            }
            else
                return number;
            index++;
        }

        return number;
    }
};