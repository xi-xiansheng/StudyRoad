class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        vector<vector<int>> dp(2, vector<int>(sz + 1, 0));
        dp[0][1] = dp[1][1] = nums[0];
        for (int i = 2; i <= sz; i++)
        {
            if (nums[i - 1] == 0)
            {
                dp[0][i] = dp[1][i] = nums[i - 1];
            }
            else
            {
                dp[0][i] = std::max(nums[i - 1], std::max(nums[i - 1] * dp[0][i - 1], nums[i - 1] * dp[1][i - 1]));
                dp[1][i] = std::min(nums[i - 1], std::min(nums[i - 1] * dp[0][i - 1], nums[i - 1] * dp[1][i - 1]));
            }
        }
        int ans = dp[0][1];
        for (int i = 1; i <= sz; i++)
        {
            if (ans < dp[0][i])
                ans = dp[0][i];
            if (ans < dp[1][i])
                ans = dp[1][i];
        }
        return ans;
    }
};