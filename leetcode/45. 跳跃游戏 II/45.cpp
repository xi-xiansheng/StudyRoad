/*class Solution {
public:
    //Ê±¼ä³¬ÏÞ
    int StepCount(const vector<int>& nums, int index)
    {
        int sz = nums.size();
        if(index == sz - 1)
        {
            return 0;
        }
        if(nums[index] == 0)
        {
            return 0x7ffffff;
        }
        int min = 0x7fffffff;
        for(int i = nums[index]; i > 0; i--)
        {
            if(i + index >= sz)
            {
                continue;
            }
            int ret = StepCount(nums, index + i);
            if(min > ret)
            {
                min = ret;
            }
        }
        return 1 + min;
    }
    int jump(vector<int>& nums) {
        return StepCount(nums, 0);
    }
};*/
/*class Solution {
public:
    //O(N^2)
    void StepCount(const vector<int>& nums)
    {
        int sz = nums.size();
        for(int i = 0; i < sz - 1; i++)
        {
            if(nums[i] == 0)
            {
                record[i] = -1;
            }
            for(int j = 1; i + j < sz && j <= nums[i]; j++)
            {
                if(record[i + j] == 0 || record[i] + 1 < record[i + j])
                {
                    record[i + j] = record[i] + 1;
                }

            }
        }
    }
    int jump(vector<int>& nums) {
        record.resize(nums.size());
        StepCount(nums);
        return record[nums.size() - 1];
    }
private:
    vector<int> record;
};*/
class Solution {
public:
    int jump(vector<int>& nums) {
        int sz = nums.size();
        int ans = 0;
        int maxnext = 0;
        int cur = 0;
        while (cur < sz - 1)
        {
            ans++;
            int tmp = maxnext;
            while (cur <= tmp)
            {
                if (cur + nums[cur] >= sz - 1)
                {
                    return ans;
                }
                if (cur + nums[cur] > maxnext)
                {
                    maxnext = cur + nums[cur];
                }
                cur++;
            }
        }
        return ans;
    }
};