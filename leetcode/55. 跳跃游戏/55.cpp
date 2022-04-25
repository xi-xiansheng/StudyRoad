/*class Solution {
public:
    bool canJump(vector<int>& nums) {
        int sz = nums.size();
        int maxnext = 0;
        int cur = 0;
        while (cur < sz - 1)
        {
            int tmp = maxnext;
            while (cur <= tmp)
            {
                if (cur + nums[cur] >= sz - 1)
                {
                    return true;
                }
                if (cur + nums[cur] > maxnext)
                {
                    maxnext = cur + nums[cur];
                }
                cur++;
            }
            if(maxnext == tmp)
                return false;
        }
        return true;
    }
};*/
class Solution {
public:

    bool Jump(const vector<int>& nums, int index)
    {
        while (index >= 0 && nums[index])
        {
            index--;
        }
        if (index == -1)
            return true;
        int cur = index - 1;
        while (cur >= 0)
        {
            if (nums[cur] + cur > index)
                return Jump(nums, cur);
            cur--;
        }
        return false;
    }

    bool canJump(vector<int>& nums) {
        return Jump(nums, nums.size() - 2);
    }
};