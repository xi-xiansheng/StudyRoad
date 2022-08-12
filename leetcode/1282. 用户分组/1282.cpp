class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        map<int, vector<int>> m;
        for (int i = 0, sz = groupSizes.size(); i < sz; i++) {
            m[groupSizes[i]].push_back(i);
        }
        for (auto& [key, value] : m) {
            int sz = value.size();
            int index = 0;
            while (index < sz) {
                int count = 0;
                vector<int> tmp(key);
                while (count < key) {
                    tmp[count++] = value[index++];
                }
                ans.push_back(tmp);
            }
        }
        return ans;
    }
};