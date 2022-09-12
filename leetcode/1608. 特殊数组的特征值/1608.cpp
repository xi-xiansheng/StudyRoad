class Solution {
public:
    int specialArray(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), greater());
        int ans = -1;
        for (int i = 0, sz = nums.size(); i < sz; i++)
        {
            if (nums[i] == 0)    break;
            while (i + 1 < sz && nums[i] == nums[i + 1])
            {
                i++;
            }
            if (nums[i] >= i + 1)    ans = i + 1;
            else
            {
                if (nums[i] >= ans)  ans = -1;
                break;
            }
        }
        return ans;
    }
};