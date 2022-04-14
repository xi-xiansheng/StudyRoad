class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> vvc;
        vector<int> vc;
        vc.resize(4);
        std::sort(nums.begin(), nums.end());
        int index = 0;
        while (index < (int)nums.size() - 3)
        {
            int left = index + 1;
            if (target < 0 && (long)nums[index] > 0)
                break;
            while (left < nums.size() - 2)
            {
                int mid = left + 1;
                int right = nums.size() - 1;
                while (mid < nums.size() - 1)
                {
                    while (right > mid)
                    {
                        /*if((target > 0 && (long)nums[index] + nums[left] + nums[mid] > (long)target))
                            break;*/
                        if (target > 0 && (long)nums[right] < 0)
                            break;
                        if ((long)nums[index] + nums[left] + nums[right] + nums[mid] > (long)target)
                        {
                            right--;
                        }
                        else if ((long)nums[index] + nums[left] + nums[right] + nums[mid] == (long)target)
                        {
                            vc[0] = nums[index];
                            vc[1] = nums[left];
                            vc[2] = nums[mid];
                            vc[3] = nums[right];
                            vvc.push_back(vc);
                            break;
                        }
                        else
                        {
                            break;
                        }
                    }
                    while ((mid + 1 < nums.size() - 1) && nums[mid] == nums[mid + 1])
                    {
                        mid++;
                    }
                    mid++;
                }
                while ((left + 1 < nums.size() - 2) && nums[left] == nums[left + 1])
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