class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int row = 0;
        int col = 0;
        vector<int> ans;
        for (int k = 0; k < m + n; k++)
        {
            if (k % 2 == 0)
            {
                int x = k < m ? k : m - 1;
                int y = k - x;
                while (x >= 0 && y < n)
                {
                    ans.push_back(mat[x][y]);
                    x--;
                    y++;
                }
            }
            else
            {
                int y = k < n ? k : n - 1;
                int x = k - y;
                while (x < m && y >= 0)
                {
                    ans.push_back(mat[x][y]);
                    x++;
                    y--;
                }
            }
        }
        return ans;
    }
};