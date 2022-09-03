class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        auto f = [=](vector<int> a, vector<int> b)->bool {
            if (a[1] < b[1]) return true;
            else if (a[1] == b[1])
            {
                return a[0] > b[0];
            }
            return false; };
        int ans = 0, cur = 0xf0000000;
        std::sort(pairs.begin(), pairs.end(), f);
        for (int i = 0, sz = pairs.size(); i < sz; i++)
        {
            if (pairs[i][0] > cur)
            {
                cur = pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};