class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> vc;
        int sz = nums.size();
        for (int i = 0; i < sz; i++)
        {
            if (nums[abs(nums[i]) - 1] < 0)
                vc.push_back(abs(nums[i]));
            else
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
        }
        return vc;
    }
};