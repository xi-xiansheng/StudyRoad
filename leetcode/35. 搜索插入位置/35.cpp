class Solution {
public:
    int BinarySearch(const vector<int>& nums, int begin, int end, int target)
    {
        while (begin <= end)
        {
            int mid = (begin + end) / 2;
            if (nums[mid] > target)
            {
                end = mid - 1;
            }
            else if (nums[mid] < target)
            {
                begin = mid + 1;
            }
            else
            {
                return mid;
            }
        }
        return -1;
    }

    int BinarySearchBigger(const vector<int>& nums, int begin, int end, int target)
    {
        //找第一个比target大的元素下标
        if (begin > end)
        {
            return -1;
        }
        int mid = (begin + end) / 2;
        if (nums[mid] > target)
        {
            int tmp = BinarySearchBigger(nums, begin, mid - 1, target);
            if (tmp != -1)
            {
                return tmp;
            }
            return mid;
        }

        int tmp = BinarySearchBigger(nums, mid + 1, nums.size() - 1, target);
        return tmp;
    }

    int searchInsert(vector<int>& nums, int target) {
        int ret = BinarySearch(nums, 0, nums.size() - 1, target);
        if (ret != -1)
        {
            return ret;
        }
        ret = BinarySearchBigger(nums, 0, nums.size() - 1, target);
        if (ret == -1)
            return nums.size();
        return ret;
    }
};