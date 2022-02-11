class Solution {
public:
    int StrToInt(string str) {
        string::iterator it = str.begin();
        int i = 0;
        int flag = 1;

        //ÅĞ¶ÏÊ×ÔªËØ
        if (*it == '+')
        {
            it++;
        }
        else if (*it == '-')
        {
            it++;
            flag = -1;
        }
        else if (*it <= '9' && *it >= '0')
        {

        }
        else
        {
            return 0;
        }
        while (it != str.end())
        {
            if (*it > '9' || *it < '0')
                return 0;
            i = i * 10 + flag * int(*it - '0');
            it++;
        }

        return i;
    }
};