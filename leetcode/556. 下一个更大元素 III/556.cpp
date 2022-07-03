class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int sz = s.size();
        int pos = -1;
        for (int i = sz - 1; i >= 0; i--)
        {
            if (i > 0 && s[i - 1] < s[i])
            {
                pos = i - 1;
                break;
            }
        }
        if (pos < 0)
            return -1;
        for (int i = sz - 1; i >= 0; i--)
        {
            if (s[pos] < s[i])
            {
                std::swap(s[i], s[pos]);
                break;
            }
        }
        int prev = pos + 1;
        int last = sz - 1;
        while (prev < last)
        {
            std::swap(s[prev], s[last]);
            prev++;
            last--;
        }
        long long dif = stol(s);
        if (dif > 0x7fffffff)
            return -1;
        return stoi(s);
    }
};