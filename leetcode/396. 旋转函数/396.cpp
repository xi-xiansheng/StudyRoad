class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int max = 0x80000000;
        int sz = nums.size();
        int prev = 0;
        int sum = 0;
        for (int i = 0; i < sz; i++)
        {
            prev += i * nums[i];
            sum += nums[i];
        }
        max = prev;
        int cur = prev;
        for (int index = 1; index < sz; index++)
        {
            prev = cur;
            cur = prev + sum - sz * nums[sz - index];
            if (cur > max)
            {
                max = cur;
            }
        }
        return max;
    }
};