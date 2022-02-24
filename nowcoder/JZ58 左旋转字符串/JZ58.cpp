/*class Solution {
public:
    string LeftRotateString(string str, int n) {
        //方法一
        if(str.size() == 0)
            return str;
        string s;
        int num = n % str.size();
        for(size_t i = 0; str[num + i] != '\0'; ++i)
        {
            s += str[i + num];
        }
        for(size_t i = 0; i < num; ++i)
        {
            s += str[i];
        }
        return s;
    }
};*/
class Solution {
public:
    string LeftRotateString(string str, int n) {
        //方法二
        if (str.size() == 0)
            return str;
        n %= str.size();
        std::reverse(str.begin(), str.begin() + n);
        std::reverse(str.begin() + n, str.end());
        std::reverse(str.begin(), str.end());
        return str;
    }
};
