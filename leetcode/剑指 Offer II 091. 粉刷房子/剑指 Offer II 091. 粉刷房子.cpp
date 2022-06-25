class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int sz = costs.size();
        vector<vector<int>> dp(sz + 1, vector<int>(3, 0));
        for (int i = 1; i < sz + 1; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                dp[i][j] = std::min(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + costs[i - 1][j];
            }
        }
        return std::min(std::min(dp[sz][0], dp[sz][1]), dp[sz][2]);
    }
};