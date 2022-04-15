class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;
        int j = nums.size() - 1;
        while (i >= 0 && nums[i] >= nums[j])
        {
            i--;
            j--;
        }
        int k = nums.size() - 1;
        if (i >= 0)
        {
            while (k >= j && nums[i] >= nums[k])
            {
                k--;
            }
            std::swap(nums[i], nums[k]);
            k = nums.size() - 1;
        }
        while (j < k)
        {
            std::swap(nums[j], nums[k]);
            j++;
            k--;
        }
    }
};