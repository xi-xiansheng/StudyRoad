class Solution {
public:

    string Rotate(string& s, int n)
    {
        if (n == 1 || n == 0)
            return s;
        int ret = 1;
        int index = 0;
        int sz = s.size();
        while (ret < n)
        {
            ret *= index + 1;
            index++;
        }
        if (ret == n)
        {
            std::reverse(s.begin() + sz - index, s.end());
            return s;
        }
        ret = ret / index;
        std::swap(s[sz - index], s[sz - index + (n - 1) / ret]);
        if (n % ret)
            std::sort(s.begin() + sz - index + 1, s.end(), less<int>());
        else
            std::sort((std::string::iterator)(s.begin() + sz - index + 1), s.end(), greater<int>());
        return Rotate(s, n - n / ret * ret);
    }

    string getPermutation(int n, int k) {
        string s;
        for (int i = 0; i < n; i++)
            s += i + '1';
        return Rotate(s, k);
    }
};