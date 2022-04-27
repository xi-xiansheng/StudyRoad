class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //剑指offer--顺时针打印矩阵
        vector<int> vc;
        int row = 0;
        int col = 0;
        int sz_col = matrix[0].size();
        int sz_row = matrix.size();
        while ((row < sz_row - row) && (2 * col < sz_col))
        {
            //从左到右
            for (int j = col; j < sz_col - col; j++)
            {
                vc.push_back(matrix[row][j]);
            }
            //自上而下
            for (int i = row + 1; i < sz_row - row; i++)
            {
                vc.push_back(matrix[i][sz_col - col - 1]);
            }
            //自右往左
            for (int j = sz_col - col - 1 - 1; (sz_row - row - 1 > row) && j >= col; j--)
            {
                vc.push_back(matrix[sz_row - row - 1][j]);
            }
            //自下而上
            for (int i = sz_row - row - 1 - 1; (col < sz_col - col - 1) && i > row; i--)
            {
                vc.push_back(matrix[i][col]);
            }
            row++;
            col++;
        }
        return vc;
    }
};