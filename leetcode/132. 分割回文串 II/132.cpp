class Solution {
public:
    int MinCut(const vector<vector<bool>>& dp)
    {
        int sz = dp.size();
        vector<int> v(sz, 0);
        for (int i = 0; i < sz; i++)
        {
            if (dp[0][i] == true)
            {
                v[i] = 0;
                continue;
            }
            else
            {
                int min = -1;
                for (int j = i; j > 0; j--)
                {
                    if (dp[j][i] == true)
                    {
                        if (min == -1 || min > v[j - 1])
                            min = v[j - 1];
                    }
                }
                v[i] = min + 1;
            }
        }
        return v[sz - 1];
    }

    int minCut(string s) {
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
        return MinCut(dp);
    }
};