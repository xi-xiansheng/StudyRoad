//Ì°ÐÄ
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int sz = prices.size();
        int cur = 0;
        while (cur < sz - 1)
        {
            if (prices[cur + 1] - prices[cur] > 0)
                profit += prices[cur + 1] - prices[cur];
            cur++;
        }
        return profit;
    }
};