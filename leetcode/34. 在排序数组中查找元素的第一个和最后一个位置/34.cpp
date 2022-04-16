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

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> vc;
        vc.resize(2);
        int ret = BinarySearch(nums, 0, nums.size() - 1, target);
        if (ret == -1)
        {
            vc[0] = vc[1] = ret;
            return vc;
        }
        //找第一个
        int left = ret;
        while (1)
        {
            int tmp = BinarySearch(nums, 0, left - 1, target);
            if (tmp == -1)
            {
                break;
            }
            else
            {
                left = tmp;
            }
        }
        vc[0] = left;
        //找最后一个
        int right = ret;
        while (1)
        {
            int tmp = BinarySearch(nums, right + 1, nums.size() - 1, target);
            if (tmp == -1)
            {
                break;
            }
            else
            {
                right = tmp;
            }
        }
        vc[1] = right;

        return vc;
    }
};