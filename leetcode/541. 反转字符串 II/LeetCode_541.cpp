class Solution {
public:
    string reverseStr(string s, int k) {
        int i = 1;
        string::iterator cur = s.begin();
        while (i < s.size())
        {
            if (i % (2 * k) == 0)
            {
                std::reverse(cur, cur + k);
                cur = cur + 2 * k;
            }
            i++;
        }
        if ((i % (2 * k) >= k && i % (2 * k) < (2 * k)) || i % (2 * k) == 0)
        {
            std::reverse(cur, cur + k);
        }
        else
        {
            std::reverse(cur, cur + i % (2 * k));
        }
        return s;
    }
};