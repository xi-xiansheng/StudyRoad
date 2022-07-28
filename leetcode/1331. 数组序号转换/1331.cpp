class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int, vector<int>> m;
        int sz = arr.size();
        for (int i = 0; i < sz; i++)
        {
            m[arr[i]].push_back(i);
        }
        int cur = 0;
        for (auto& v : m)
        {
            cur++;
            for (auto& index : v.second)
            {
                arr[index] = cur;
            }
        }
        return arr;
    }
};