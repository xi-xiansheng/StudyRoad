class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int sz = nums.size();
        std::sort(nums.begin(), nums.end());
        vector<int> log;
        log.resize(sz);
        int index = 0;
        _permute(nums, log, index);
        return vvc;
    }
    void _permute(vector<int>& nums, vector<int>& log, int index)
    {
        int sz = nums.size();
        if (index == sz)
        {
            vvc.push_back(log);
            return;
        }
        for (int i = index; i < sz; i++)
        {
            std::swap(nums[index], nums[i]);
            log[index] = nums[index];
            vector<int> tmp(nums);
            std::sort(tmp.begin() + index + 1, tmp.end());
            _permute(tmp, log, index + 1);
            std::swap(nums[index], nums[i]);
            while (i + 1 < sz && nums[i] == nums[i + 1])
            {
                i++;
            }
        }
    }

private:
    vector<vector<int>> vvc;
};