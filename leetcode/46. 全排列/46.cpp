class Solution {
public:
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
            _permute(nums, log, index + 1);
            std::swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int sz = nums.size();
        vector<int> log;
        log.resize(sz);
        int index = 0;
        _permute(nums, log, index);
        return vvc;
    }
private:
    vector<vector<int>> vvc;
};