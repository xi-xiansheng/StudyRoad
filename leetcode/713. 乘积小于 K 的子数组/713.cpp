/*class Solution {
public:
    int Find(const vector<int> nums, int index, int k)
    {
        if(index < 0)
            return 0;
        int count = 0;
        if(nums[index] <= k)
        {
            count++;
            count += Find(nums, index - 1, k / nums[index]);
        }
        return count;
    }

    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int index = nums.size() - 1;
        k--;
        while(index >= 0)
        {
            if(nums[index] <= k)
                count += Find(nums, index, k);
            index--;
        }
        return count;
    }
};*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int count = 0;
        int sz = nums.size();
        int left = 0;
        int right = 0;
        int mul = 1;
        while (right < sz)
        {
            mul *= nums[right];
            while (left <= right && mul >= k)
            {
                mul /= nums[left];
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
};