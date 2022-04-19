class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int cur = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (cur < 0)
                cur = 0;
            cur += nums[i];
            if (sum < cur)
                sum = cur;
        }
        return sum;
    }
};