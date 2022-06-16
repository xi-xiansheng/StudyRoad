class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        unordered_set<int> hash;
        for (auto& n : nums)
        {
            mp[n]++;
        }
        for (auto& n : nums)
        {
            if (hash.count(n) == 0 && mp[n + k] != 0) {
                if (k == 0 && mp[n + k] == 1)
                {
                    continue;
                }
                hash.insert(n);
            }
        }
        return hash.size();
    }
};