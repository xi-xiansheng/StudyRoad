class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int sz = p.size();
        vector<int> dp(sz + 1, 0);
        vector<int> dict(26, 0);
        dp[0] = 1;
        dict[p[0] - 'a'] = 1;
        for (int i = 0; i < sz - 1; i++)
        {
            if ((p[i + 1] - 'a') % 26 == (p[i] - 'a' + 1) % 26)
                dp[i + 1] = dp[i] + 1;
            else
                dp[i + 1] = 1;
            if (dp[i + 1] > dict[p[i + 1] - 'a'])
                dict[p[i + 1] - 'a'] = dp[i + 1];
        }
        int res = 0;
        for (const int& e : dict)
        {
            res += e;
        }
        return res;
    }
};