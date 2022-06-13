class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int count = 0;
        vector<int> res(heights);
        std::sort(res.begin(), res.end());
        int sz = res.size();
        for (int i = 0; i < sz; i++)
        {
            if (res[i] != heights[i])
                count++;
        }
        return count;
    }
};