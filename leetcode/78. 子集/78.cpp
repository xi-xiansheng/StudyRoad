class Solution {
public:
    void Sub(const vector<int>& nums, vector<int> vc, int index)
    {
        int sz = nums.size();
        subset.push_back(vc);
        if (index >= sz)
            return;
        vector<int> tmp(vc);
        tmp.resize(index + 1);
        int res = _start;
        for (int i = _start; i < sz; i++)
        {
            tmp[index] = nums[i];

            _start = i + 1;
            Sub(nums, tmp, index + 1);
        }
        _start = res;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        _start = 0;
        Sub(nums, vector<int>(), 0);
        return subset;
    }
private:
    vector<vector<int>> subset;
    int _start;
};