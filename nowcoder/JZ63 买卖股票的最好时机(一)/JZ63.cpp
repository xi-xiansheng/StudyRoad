class Solution {
public:
    /**
     *
     * @param prices int整型vector
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        // write code here
        int buy = 0;
        int profit = 0;
        int cur = 0;
        while (cur < prices.size())
        {
            if (prices[buy] > prices[cur])
            {
                buy = cur;
            }
            if (prices[cur] - prices[buy] > profit)
            {
                profit = prices[cur] - prices[buy];
            }
            cur++;
        }
        return profit;
    }
};