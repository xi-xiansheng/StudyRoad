class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> ret(2);
        int sz = arr.size();
        for (int i = 0; i < sz - 1; i++)
        {
            int dif = arr[i + 1] - arr[i];
            if (ans.size() == 0 || dif == ans[0][1] - ans[0][0])
            {
                ret[0] = arr[i];
                ret[1] = arr[i + 1];
                ans.push_back(ret);
            }
            else if (dif < ans[0][1] - ans[0][0])
            {
                ans.clear();
                ret[0] = arr[i];
                ret[1] = arr[i + 1];
                ans.push_back(ret);
            }
        }
        return ans;
    }
};