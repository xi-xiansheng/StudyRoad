class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sz = prices.size();
        if (sz == 0)
            return 0;
        vector<vector<vector<int>>> dp(sz, vector<vector<int>>(2, vector<int>(3, 0)));
        //≥ı ºªØ
        dp[0][0][0] = 0;
        dp[0][0][1] = dp[0][1][1] = dp[0][0][2] = 0x8fffffff;
        dp[0][1][0] = -prices[0];

        for (int i = 1; i < sz; i++)
        {
            dp[i][0][0] = 0;
            dp[i][0][1] = std::max(dp[i - 1][0][1], dp[i - 1][1][0] + prices[i]);
            dp[i][0][2] = std::max(dp[i - 1][0][2], dp[i - 1][1][1] + prices[i]);
            dp[i][1][0] = std::max(dp[i - 1][1][0], dp[i - 1][0][0] - prices[i]);
            dp[i][1][1] = std::max(dp[i - 1][1][1], dp[i - 1][0][1] - prices[i]);
        }
        return std::max(dp[sz - 1][0][2], std::max(dp[sz - 1][0][1], 0));
    }
};