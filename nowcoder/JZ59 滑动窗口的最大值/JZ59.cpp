class Solution {
public:
    vector<int> maxInWindows(const vector<int>& nums, int size) {
        //
        int maxindex = 0;
        int cur = 0;
        int last = 0;
        vector<int> vc;
        while (cur < nums.size() && cur < size - 1)
        {
            if (nums[maxindex] <= nums[cur])
                maxindex = cur;
            cur++;
        }
        while (cur < nums.size())
        {
            //更新窗口最大值下标
            if (maxindex >= last && nums[maxindex] <= nums[cur])
                maxindex = cur;
            //新的区间找最大值
            if (maxindex < last)
            {
                int tmp = last;
                maxindex = last;
                while (tmp <= cur)
                {
                    if (nums[tmp] >= nums[maxindex])
                        maxindex = tmp;
                    tmp++;
                }
            }
            //进数组
            vc.push_back(nums[maxindex]);
            cur++;
            last++;
        }
        return vc;
    }
};