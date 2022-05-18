class Solution {
public:
    /*int findKthNumber(int m, int n, int k) {
        vector<vector<int>> vv(m, vector<int>(n, 1));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                vv[i][j] = (i + 1) * (j + 1);
            }
        }
        vector<int> res;
        for(auto e : vv)
        {
            for(auto ee : e)
            {
                res.push_back(ee);
            }
        }
        std::sort(res.begin(), res.end());
        return res[k - 1];
    }*/
    int allsubs(int num, int m, int n)
    {
        int res = 0;
        for (int i = 1; i <= m; i++)
            res += min(num / i, n);
        return res;
    }

    int findKthNumber(int m, int n, int k) {
        int left = 1;
        int right = m * n;
        while (left < right)
        {
            int mid = (left + right) / 2;
            int midcount = allsubs(mid, m, n);
            if (midcount < k)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }
};