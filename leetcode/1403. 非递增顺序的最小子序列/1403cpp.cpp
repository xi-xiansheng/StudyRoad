class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        vector<int> ans;
        priority_queue<int> q;
        int sum = 0, anssum = 0;
        for (auto& e : nums)
        {
            sum += e;
            q.emplace(e);
        }
        while (anssum <= sum)
        {
            int ret = q.top();
            q.pop();
            sum -= ret;
            anssum += ret;
            ans.push_back(ret);
        }
        return ans;
    }
};