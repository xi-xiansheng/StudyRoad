class Solution {
public:

    void  PalindromesPush(vector<string>& v, const string& s, const vector<vector<bool>>& dp, int index)
    {
        int sz = s.size();
        if (index >= sz)
        {
            ans.push_back(v);
            return;
        }
        for (int i = index; i < sz; i++)
        {
            if (dp[index][i])
            {
                string tmp(s.begin() + index, s.begin() + i + 1);
                v.push_back(tmp);
                PalindromesPush(v, s, dp, i + 1);
                v.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        int sz = s.size();
        vector<vector<bool>> dp(sz, vector<bool>(sz, true));
        for (int index = 1; index < sz * 2; index++)
        {
            int left = (index - 1) / 2;
            int right = index / 2;
            while (left >= 0 && right < sz)
            {
                dp[left][right] = (s[left] == s[right]) && (right - left < 2 || dp[left + 1][right - 1]);
                left--;
                right++;
            }
        }
        PalindromesPush(res, s, dp, 0);
        return ans;
    }
private:
    vector<vector<string>> ans;
    vector<string> res;
};