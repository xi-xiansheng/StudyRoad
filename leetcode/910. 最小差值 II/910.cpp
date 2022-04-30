class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        std::sort(nums.begin(), nums.end());
        int sz = nums.size();
        int result = nums[sz - 1] - nums[0];
        if (nums[sz - 1] - nums[0] <= k)
            return nums[sz - 1] - nums[0];
        for (int i = 0; i < sz - 1; i++)
        {
            int _max = (nums[i] + k) > (nums[sz - 1] - k) ? (nums[i] + k) : (nums[sz - 1] - k);
            int _min = (nums[0] + k) < (nums[i + 1] - k) ? (nums[0] + k) : (nums[i + 1] - k);
            if (_max - _min < result)
                result = _max - _min;
        }
        return result;
    }
};