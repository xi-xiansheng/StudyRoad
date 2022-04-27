class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int Squarexy = 0;
        int Squarexz = 0;
        int Squareyz = 0;
        int sz_row = grid.size();
        int sz_col = grid[0].size();
        for (int i = 0; i < sz_row; i++)
        {
            int max = 0;
            for (int j = 0; j < sz_col; j++)
            {
                if (grid[i][j])
                {
                    Squarexy += 1;
                    if (grid[i][j] > max)
                        max = grid[i][j];
                }
            }
            Squarexz += max;
        }
        for (int j = 0; j < sz_col; j++)
        {
            int max = 0;
            for (int i = 0; i < sz_row; i++)
            {
                if (grid[i][j] > max)
                    max = grid[i][j];
            }
            Squareyz += max;
        }
        return Squarexy + Squarexz + Squareyz;
    }
};