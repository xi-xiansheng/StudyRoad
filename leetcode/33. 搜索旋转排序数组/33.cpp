class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right) / 2;
        //找出最大值下标
        while (left + 1 < right)
        {
            if (nums[left] > nums[mid])
            {
                right = mid;
            }
            else
            {
                left = mid;
            }
            mid = (left + right) / 2;
        }
        if (nums[mid] < nums[right])
        {
            mid = right;
        }
        if (target > nums[0])
        {
            left = 0;
            right = mid;
            while (left <= right)
            {
                mid = (left + right) / 2;
                if (nums[mid] > target)
                {
                    right = mid - 1;
                }
                else if (nums[mid] == target)
                {
                    return mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        else if (target == nums[0])
        {
            return 0;
        }
        else
        {
            left = mid + 1;
            right = nums.size() - 1;
            while (left <= right)
            {
                mid = (left + right) / 2;
                if (nums[mid] > target)
                {
                    right = mid - 1;
                }
                else if (nums[mid] == target)
                {
                    return mid;
                }
                else
                {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};