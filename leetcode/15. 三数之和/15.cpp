class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> vvc;
        vector<int> vc;
        vc.resize(3);
        std::sort(nums.begin(), nums.end());
        int index = 0;
        while (index < (int)nums.size() - 2 && nums[index] <= 0)
        {
            int left = index + 1;
            int right = nums.size() - 1;
            //注：right不可在下一个循环内创建，否则无法AC，在此处创建减少循环   O(N^2)
            while (left < nums.size() - 1)
            {
                if (nums[index] + nums[left] > 0)
                    break;
                while (right > left && nums[right] >= 0)
                {
                    if (nums[index] + nums[left] + nums[right] > 0)
                    {
                        right--;;
                    }
                    else if (nums[index] + nums[left] + nums[right] == 0)
                    {
                        vc[0] = nums[index];
                        vc[1] = nums[left];
                        vc[2] = nums[right];
                        vvc.push_back(vc);
                        break;
                    }
                    else
                    {
                        break;
                    }
                }
                while ((left + 1 < nums.size() - 1) && nums[left] == nums[left + 1])
                {
                    left++;
                }
                left++;
            }
            while ((index + 1 < nums.size() - 1) && nums[index] == nums[index + 1])
            {
                index++;
            }
            index++;
        }
        return vvc;
    }
};