class Solution {
public:

    int Minimal(int a, int b, int c)
    {
        a = a < b ? a : b;
        return a < c ? a : c;
    }

    int minDistance(string word1, string word2) {
        int sz1 = word1.size();
        int sz2 = word2.size();
        vector<vector<int>> dp(sz1 + 1, vector<int>(sz2 + 1, 0));
        for (int i = 0; i < sz1 + 1; i++)
            dp[i][0] = i;
        for (int j = 0; j < sz2 + 1; j++)
            dp[0][j] = j;
        for (int i = 1; i < sz1 + 1; i++)
        {
            for (int j = 1; j < sz2 + 1; j++)
            {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = Minimal(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
            }
        }
        return dp[sz1][sz2];
    }
};