class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        //Ë«Ö¸Õë
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right)
        {
            while (right >= left && nums[right] == val)
            {
                nums.resize(right);
                right--;
            }
            while (left <= right && nums[left] != val)
            {
                left++;
            }
            if (left > right)
            {
                break;
            }
            std::swap(nums[left], nums[right]);
        }
        return nums.size();
    }
};