/*class Solution {
public:
    //µÝ¹é°æ±¾
    bool _match(string s, string p, int i, int j)
    {
        if (i == -1 && j == -1)
            return true;
        if (j == -1)
            return false;
        if (i != -1 && (s[i] == p[j] || p[j] == '.'))
            return _match(s, p, i - 1, j - 1);
        if (p[j] == '*')
        {
            if (i == -1)
                return _match(s, p, i, j - 2);
            if (p[j - 1] == s[i] || p[j - 1] == '.')
            {
                return  _match(s, p, i, j - 2) || _match(s, p, i - 1, j);
            }
            else
                return _match(s, p, i, j - 2);
        }
        return false;
    }
    bool isMatch(string s, string p) {
        return _match(s, p, s.size() - 1, p.size() - 1);
    }
};*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size();
        int plen = p.size();
        vector<vector<bool>> dp;
        dp.resize(slen + 1);
        for (int i = 0; i <= slen; i++)
        {
            dp[i].resize(plen + 1);
            for (int j = 0; j <= plen; j++)
            {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;
        for (int j = 1; j < plen + 1; j++)
        {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
        }
        for (int i = 1; i <= slen; i++)
        {
            for (int j = 1; j <= plen; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                {
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.')
                        dp[i][j] = dp[i][j - 2] || dp[i - 1][j];
                    else
                        dp[i][j] = dp[i][j - 2];
                }
            }
        }
        return dp[slen][plen];
    }
};