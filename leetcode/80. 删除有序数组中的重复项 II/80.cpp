class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sz = nums.size();
        while (left < sz && right < sz)
        {
            nums[left] = nums[right];
            if (right + 1 < sz && nums[right] == nums[right + 1])
            {
                while (right + 1 < sz && nums[right] == nums[right + 1])
                {
                    right++;
                }
                nums[left + 1] = nums[left];
                left++;
            }
            left++;
            right++;
        }
        return sz - right + left;
    }
};