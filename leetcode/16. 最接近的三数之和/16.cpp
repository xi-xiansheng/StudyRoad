class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int index = 0;
        int ans = nums[0] + nums[1] + nums[2];
        while (index < (int)nums.size() - 2)
        {
            int left = index + 1;
            int right = nums.size() - 1;
            while (left < right)
            {
                if (nums[index] + nums[left] + nums[right] > target)
                {
                    if (abs(nums[index] + nums[left] + nums[right] - target) < abs(ans - target))
                        ans = nums[index] + nums[left] + nums[right];
                    right--;
                }
                else if (nums[index] + nums[left] + nums[right] < target)
                {
                    if (abs(nums[index] + nums[left] + nums[right] - target) < abs(ans - target))
                        ans = nums[index] + nums[left] + nums[right];
                    left++;
                }
                else
                {
                    return target;
                }
            }
            while ((index + 1 < nums.size() - 1) && nums[index] == nums[index + 1])
            {
                index++;
            }
            index++;
        }
        return ans;
    }
};