class Solution {
public:
    int countPalindromicSubsequences(string s) {
        int sz = s.size();
        vector<vector<int>> dp(sz + 2, vector<int>(sz + 2, 0));
        for (int i = 1; i <= sz; i++)
        {
            dp[i][i] = 1;
        }
        for (int len = 2; len <= sz; len++)
        {
            for (int i = 1; i + len - 1 <= sz; i++)
            {
                int j = i + len - 1;
                if (s[i - 1] == s[j - 1] && i != j)
                {
                    int count = 0;
                    for (int k = i + 1; k < j; k++)
                    {
                        if (s[k - 1] == s[i - 1])
                            count++;
                    }
                    if (count == 0)
                        dp[i][j] = (2 * dp[i + 1][j - 1] + 2) % 1000000007;
                    else if (count == 1)
                        dp[i][j] = (2 * dp[i + 1][j - 1] + 1) % 1000000007;
                    else
                    {
                        int left = -1;
                        for (int k = i + 1; k < j; k++)
                        {
                            if (s[k - 1] == s[i - 1])
                            {
                                left = k;
                                break;
                            }
                        }
                        int right = -1;
                        for (int k = j - 1; k > i; k--)
                        {
                            if (s[k - 1] == s[i - 1])
                            {
                                right = k;
                                break;
                            }
                        }
                        dp[i][j] = (2 * dp[i + 1][j - 1] - dp[left + 1][right - 1]) % 1000000007;
                    }
                }
                else if (s[i - 1] != s[j - 1])
                {
                    dp[i][j] = (dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1]) % 1000000007;
                }
                if (dp[i][j] < 0)
                    dp[i][j] += 1000000007;
            }
        }
        return (int)dp[1][sz];
    }
};