class Solution {
public:
    bool dfs(int state, int tot, const int& desiredTotal)
    {
        if (v[state])
            return v[state] == 1;
        for (int i = 0; i < n; i++)
        {
            if ((state >> i) & 1)
                continue;
            if (tot + i + 1 >= desiredTotal)
            {
                v[state] = 1;
                return true;
            }

            if (!dfs(state | (1 << i), tot + i + 1, desiredTotal))
            {
                v[state] = 1;
                return true;
            }
        }
        v[state] = -1;
        return false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if (maxChoosableInteger >= desiredTotal)
            return true;
        if (maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal)
            return false;
        n = maxChoosableInteger;
        v.resize(1 << maxChoosableInteger);
        return dfs(0, 0, desiredTotal);
    }

private:
    vector<int> v;
    int n;
};