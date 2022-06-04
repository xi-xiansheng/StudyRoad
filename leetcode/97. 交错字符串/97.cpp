class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int rows = s1.size();
        int cols = s2.size();
        if (rows + cols != s3.size())
            return false;
        vector<vector<bool>> dp(rows + 1, vector<bool>(cols + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < rows; i++)
        {
            dp[i + 1][0] = (s1[i] == s3[i] && dp[i][0]);
        }
        for (int j = 0; j < cols; j++)
        {
            dp[0][j + 1] = (s2[j] == s3[j] && dp[0][j]);
        }
        for (int i = 1; i <= rows; i++)
        {
            for (int j = 1; j <= cols; j++)
            {
                dp[i][j] = (dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) ||
                    (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        /*for(int i = 0; i <= rows; i++)
        {
            for(int j = 0; j <= cols; j++)
            {
                if(dp[i][j])
                    cout << "true  ";
                else
                    cout << "false ";
            }
            cout << endl;
        }*/
        return dp[rows][cols];
    }
};