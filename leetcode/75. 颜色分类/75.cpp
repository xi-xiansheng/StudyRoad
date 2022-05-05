/*class Solution {
public:
    void sortColors(vector<int>& nums) {
        int numblue = 0;
        int numred = 0;
        int numwhite = 0;
        for(auto e : nums)
        {
            if(e == 0)
                numred++;
            if(e == 1)
                numwhite++;
            if(e == 2)
                numblue++;
        }
        int index = 0;
        while(numred--)
        {
            nums[index++] = 0;
        }
        while(numwhite--)
        {
            nums[index++] = 1;
        }
        while(numblue--)
        {
            nums[index++] = 2;
        }
    }
};*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int sz = nums.size();
        int left = 0;
        int right = sz - 1;
        int index = 0;
        while (index <= right)
        {
            if (nums[index] == 0)
            {
                std::swap(nums[index], nums[left]);
                left++;
                index++;
            }
            else if (nums[index] == 2)
            {
                std::swap(nums[index], nums[right]);
                right--;
            }
            else
                index++;
        }
    }
};