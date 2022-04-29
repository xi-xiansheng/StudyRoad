class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> vvc(m + 1, vector<int>(n + 1, 0));
        vvc[1][0] = 1 - obstacleGrid[0][0];
        for (int j = 1; j <= n; j++)
        {
            if (obstacleGrid[0][j - 1])
                vvc[1][j] = 0;
            else
                vvc[1][j] = vvc[1][j - 1];
        }
        for (int i = 2; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (obstacleGrid[i - 1][j - 1])
                    vvc[i][j] = 0;
                else
                    vvc[i][j] = vvc[i - 1][j] + vvc[i][j - 1];
            }
        }
        return vvc[m][n];
    }
};