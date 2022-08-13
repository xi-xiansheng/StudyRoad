class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> cmp(arr);
        std::sort(cmp.begin(), cmp.end());
        map<int, int> m;
        int ans = 0;
        for (int i = 0, sz = arr.size(); i < sz; i++) {
            m[arr[i]] += 1;
            m[cmp[i]] -= 1;
            if (m[cmp[i]] == 0)
                m.erase(cmp[i]);
            if (m[arr[i]] == 0)
                m.erase(arr[i]);
            if (m.size() == 0)
                ans++;
        }
        return ans;
    }
};