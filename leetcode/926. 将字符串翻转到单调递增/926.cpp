class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(2, 0));
        for (int i = 1; i <= s.size(); i++)
        {
            dp[i][0] = dp[i - 1][0] + (s[i - 1] == '1' ? 1 : 0);
            dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]) + (s[i - 1] == '0' ? 1 : 0);
        }
        return std::min(dp[s.size()][0], dp[s.size()][1]);
    }
};