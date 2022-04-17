/*class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> vc;
        int sz = nums.size() + 1;
        vc.resize(sz);
        for(auto e : nums)
        {
            if(e <= 0 || e > sz)
            {
                continue;
            }
            vc[e - 1] += 1;
        }
        for(int i = 0; i < sz; i++)
        {
            if(vc[i] == 0)
                return i + 1;
        }
        return sz;
    }
};*/

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int sz = nums.size();
        for (int index = 0; index < sz; index++)
        {
            if (nums[index] <= 0 || nums[index] > sz)
            {
                continue;
            }
            if (nums[index] != nums[nums[index] - 1])
            {
                std::swap(nums[index], nums[nums[index] - 1]);
                index--;
            }
        }
        for (int index = 0; index < sz; index++)
        {
            if (nums[index] != index + 1)
            {
                return index + 1;
            }
        }
        return sz + 1;
    }
};
