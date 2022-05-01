class Solution {
public:
    bool isNumber(string s) {
        bool EExist = false;
        bool PointExist = false;
        int sz = s.size();
        int index = 0;
        /*if(!((isdigit(s[index]) || s[index] == '+' || s[index] == '-')) || sz == 0)
            return false;*/
        if (sz == 0)
            return false;
        if (s[0] == '-' || s[0] == '+')
        {
            if (sz == 1)
                return false;
            index++;
        }
        while (index < sz)
        {
            if (s[index] == '.')
            {
                if (PointExist || EExist)
                    return false;
                if ((index - 1 >= 0 && isdigit(s[index - 1])) || (index + 1 < sz && isdigit(s[index + 1])))
                    PointExist = true;
                else
                    return false;
            }
            else if (s[index] == 'E' || s[index] == 'e')
            {
                if (EExist || index == 0 || index == sz - 1 || !(isdigit(s[index - 1]) || s[index - 1] == '.'))
                    return false;
                EExist = true;
                if (index + 1 >= sz)
                    return false;
            }
            else if (s[index] == '+' || s[index] == '-')
            {
                if (!EExist || (index - 1 < 0) || (index + 1 >= sz))
                    return false;
                if (s[index - 1] != 'e' && s[index - 1] != 'E')
                    return false;
                if (!isdigit(s[index + 1]))
                    return false;
            }
            else if (isdigit(s[index]))
            {
                ;
            }
            else
                return false;
            index++;
        }
        return true;
    }
};