class Solution {
public:
    int maxEqualFreq(vector<int>& nums) {
        int ans = 0;
        unordered_map<int, int> count;
        unordered_map<int, int> frequency;
        int max = 0;
        for (int i = 0, sz = nums.size(); i < sz; i++)
        {
            count[nums[i]] += 1;
            frequency[count[nums[i]]] += 1;
            frequency[count[nums[i]] - 1] -= 1;
            max = std::max(max, count[nums[i]]);
            if (max == 1)
            {
                ans = i + 1;
            }
            else if (max * frequency[max] == i)
            {
                ans = i + 1;
            }
            else if ((max - 1) * (frequency[max - 1] + 1) == i)
            {
                ans = i + 1;
            }
        }
        return ans;
    }
};