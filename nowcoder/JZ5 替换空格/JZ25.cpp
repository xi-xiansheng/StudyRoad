class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return string字符串
     */
    string replaceSpace(string s) {
        // write code here
        int count = 0;
        int j = 0;
        while (j < s.size())
        {
            if (s[j] == ' ')
                count++;
            j++;
        }
        int newlength = s.size() + 2 * count + 1;
        int oldlength = s.size() + 1;
        s.resize(newlength);
        while (oldlength >= 0 && newlength >= 0)
        {
            if (s[oldlength] == ' ')
            {
                s[newlength--] = '0';
                s[newlength--] = '2';
                s[newlength--] = '%';
                oldlength--;
            }
            else
            {
                s[newlength--] = s[oldlength--];
            }
        }
        return s;
    }
};