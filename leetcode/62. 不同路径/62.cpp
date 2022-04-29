/*class Solution {
public:

    int Paths(int m, int n, int x, int y)
    {
        if(x == m  - 1 && y == n - 1)
            return 1;
        if(y == n - 1)
            return Paths(m, n, x + 1, y);
        if(x == m  - 1)
            return Paths(m, n, x, y + 1);
        return Paths(m, n, x + 1, y) + Paths(m, n, x, y + 1);
    }

    int uniquePaths(int m, int n) {
        return Paths(m, n, 0, 0);
    }
};*/
class Solution {
public:

    int uniquePaths(int m, int n) {
        vector<vector<int>> vvc(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == 0 || j == 0)
                    vvc[i][j] = 1;
                else
                    vvc[i][j] = vvc[i - 1][j] + vvc[i][j - 1];
            }
        }
        return vvc[m - 1][n - 1];
    }
};