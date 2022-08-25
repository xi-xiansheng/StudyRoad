class Solution {
public:
    int maxProduct(vector<int>& nums) {
        priority_queue<int, vector<int>, std::greater<int>> q;
        q.push(nums[0]);
        q.push(nums[1]);
        for (int i = 2, sz = nums.size(); i < sz; i++)
        {
            if (nums[i] >= q.top())
            {
                q.pop();
                q.push(nums[i]);
            }
        }
        int f = q.top();
        q.pop();
        return (f - 1) * (q.top() - 1);
    }
};