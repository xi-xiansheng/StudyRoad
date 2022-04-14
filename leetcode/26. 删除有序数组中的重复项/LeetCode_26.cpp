class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        size_t count = 0;
        size_t i = 0;
        while (i + count + 1 < nums.size())
        {
            while (i + count + 1 < nums.size() && nums[i] == nums[i + count + 1])
            {
                count++;
            }
            i++;
            if (i + count < nums.size())
                nums[i] = nums[i + count];
        }
        return nums.size() - count;
    }
};