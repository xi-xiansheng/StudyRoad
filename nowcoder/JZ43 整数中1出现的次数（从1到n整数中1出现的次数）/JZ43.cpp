class Solution {
public:

    int NumberOf1Between1And(const char* str)
    {
        if (!str || *str < '0' || *str == '\0')
            return 0;
        int first = *str - '0';
        int lenth = strlen(str);
        if (first == 0 && lenth == 1)
            return 0;
        if (first > 0 && lenth == 1)
            return 1;
        int number = atoi(str);
        int count1 = 0;
        //判断首位情况
        if (first > 1)
            count1 += int(pow(10, lenth - 1));
        else if (first == 1)
            count1 += atoi(str + 1) + 1;

        //
        count1 += first * (lenth - 1) * int(pow(10, lenth - 2));

        count1 += NumberOf1Between1And(str + 1);

        return count1;
    }


    int NumberOf1Between1AndN_Solution(int n) {
        string s1;
        while (n)
        {
            s1 += n % 10 + '0';
            n /= 10;
        }
        int i = 0;
        while (i < s1.size() / 2)
        {
            std::swap(s1[i], s1[s1.size() - i - 1]);
            i++;
        }
        char str[s1.size() + 1];
        std::strcpy(str, s1.c_str());
        return NumberOf1Between1And(str);
    }
};