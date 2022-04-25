class Solution {
public:
    /*bool _match(const string s, const string p, int i, int j)
    {
        if(i == -1 && j == -1)
            return true;
        if(i == -1)
        {
            if(p[j] == '*')
                return _match(s, p, i, j - 1);
            return false;
        }
        if(j == -1)
            return false;
        if(s[i] == p[j] || p[j] == '?')
            return _match(s, p, i - 1, j- 1);
        if(p[j] == '*')
        {
            while(j - 1 >= 0 && p[j - 1] == '*')
            {
                j--;
            }
            return _match(s, p, i, j- 1) || _match(s, p, i - 1, j);    // _match(s, p, i - 1, j- 1);
        }
        return false;
    }*/
    /*bool _match(const string s, const string p, int i, int j)
    {
        int sz = s.size();
        int pz = p.size();
        if(i == sz && j == pz)
            return true;
        if(i == sz)
        {
            if(p[j] == '*')
                return _match(s, p, i, j + 1);
            return false;
        }
        if(j == pz)
            return false;
        if(s[i] == p[j] || p[j] == '?')
            return _match(s, p, i + 1, j + 1);
        if(p[j] == '*')
        {
            while(j + 1 < pz && p[j + 1] == '*')
            {
                j++;
            }
            return _match(s, p, i, j + 1) || _match(s, p, i + 1, j); // _match(s, p, i + 1, j + 1);
        }
        return false;
    }*/


    bool isMatch(string s, string p) {
        //return _match(s, p, 0, 0);
        //return _match(s, p, s.size() - 1, p.size() - 1);
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
                dp[0][j] = dp[0][j - 1];
        }
        for (int i = 1; i <= slen; i++)
        {
            for (int j = 1; j <= plen; j++)
            {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                {
                    dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                }
            }
        }
        return dp[slen][plen];
    }
};