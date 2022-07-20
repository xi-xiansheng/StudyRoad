class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cocls = grid[0].size();
        k %= rows * cocls;
        vector<vector<int>> ret(rows, vector<int>(cocls));
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cocls; j++)
            {
                ret[(i + (j + k) / cocls) % rows][(j + k) % cocls] = grid[i][j];
            }
        }
        std::swap(ret, grid);
        return grid;
    }
};