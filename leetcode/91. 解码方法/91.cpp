class Solution {
public:
    int numDecodings(string s) {
        s = "0" + s;
        int sz = s.size();
        vector<int> dp(sz + 1, 0);
        dp[1] = 1;
        for (int i = 1; i < sz; i++)
        {
            int a = s[i] - '0';
            int b = a + 10 * (s[i - 1] - '0');
            if (1 <= a && a <= 9)
            {
                if (10 <= b && b <= 26)
                    dp[i + 1] = dp[i - 1] + dp[i];
                else
                    dp[i + 1] = dp[i];
            }
            else if (10 <= b && b <= 26)
                dp[i + 1] = dp[i - 1];
            else
                return 0;
        }
        return dp[sz];
    }
};