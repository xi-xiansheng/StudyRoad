class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int l = 0, r = 0;
        for (auto ch : s)
        {
            if (ch == '(')
            {
                l++;
            }
            else
            {
                if (l)   l--;
                else
                {
                    ans++;
                    r++;
                }
            }
        }
        return abs(ans) + l;
    }
};