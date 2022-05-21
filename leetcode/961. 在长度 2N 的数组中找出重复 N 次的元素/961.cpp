class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> m;
        for (auto e : nums)
        {
            m[e] += 1;
            if (m[e] > 1)
                return e;
        }
        return 0;
    }
};