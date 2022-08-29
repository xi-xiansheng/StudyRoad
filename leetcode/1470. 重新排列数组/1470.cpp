class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(nums);
        for (int i = 0, index = 0; i < 2 * n; i += 2, index++)
        {
            ans[i] = nums[index];
            ans[i + 1] = nums[index + n];
        }
        return ans;
    }
};