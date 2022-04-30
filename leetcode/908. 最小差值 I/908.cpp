class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int min = nums[0];
        int max = nums[0];
        for (auto e : nums)
        {
            if (e > max)
                max = e;
            if (e < min)
                min = e;
        }
        int result = abs(max - min);
        if (result > 2 * k)
            return result - 2 * k;
        return 0;
    }
};