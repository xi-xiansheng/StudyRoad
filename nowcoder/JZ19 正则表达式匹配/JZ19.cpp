class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @param pattern string字符串
     * @return bool布尔型
     */
    bool _match(const string& str, string pattern, int index1, int index2)
    {
        //if(((str[index1] == '\0') + (pattern[index2] == '\0')) == 1)
            //return false;
        if (str[index1] == '\0' && pattern[index2] == '\0')
            return true;
        if (pattern[index2] == '.' && pattern[index2 + 1] != '*')
            pattern[index2] = str[index1];
        if (str[index1] != pattern[index2] && pattern[index2 + 1] != '*')
            return false;
        if (pattern[index2 + 1] && pattern[index2 + 1] == '*')
        {
            if (str[index1] == pattern[index2])
            {
                int pos1 = index1;
                while (str[pos1] && str[index1] == str[pos1])
                {
                    pos1++;
                }
                int pos2 = index2 + 2;
                while (pattern[pos2])
                {
                    if (pattern[index2] != pattern[pos2])
                    {
                        if (pattern[pos2] == '.')
                        {
                            if (_match(str, pattern, pos1, pos2))
                                return true;
                        }
                        else if (pattern[pos2] == '*')
                        {
                            ;
                        }
                        else
                        {
                            if (pattern[pos2 + 1] != '*')
                                break;
                            else
                            {
                                if (_match(str, pattern, pos1, pos2))
                                    return true;
                            }
                        }
                    }
                    pos2++;
                }
                return _match(str, pattern, pos1, pos2);
            }
            else
            {
                if (pattern[index2] == '.')
                {
                    if (pattern[index2 + 2] == '\0')
                        return true;
                    int pos = index1;
                    while (str[pos])
                    {
                        if (_match(str, pattern, pos, index2 + 2))
                            return true;
                        pos++;
                    }
                }
                return _match(str, pattern, index1, index2 + 2);
            }
        }

        return _match(str, pattern, index1 + 1, index2 + 1);
    }

    bool match(string str, string pattern) {
        // write code here
        return _match(str, pattern, 0, 0);
    }
};