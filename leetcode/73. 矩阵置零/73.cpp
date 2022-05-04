class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> vr(rows, 0);
        vector<int> vc(cols, 0);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (matrix[i][j] == 0)
                {
                    vr[i] = 1;
                    vc[j] = 1;
                }
            }
        }
        for (int i = 0; i < rows; i++)
            if (vr[i])
                for (int j = 0; j < cols; j++)
                    matrix[i][j] = 0;
        for (int j = 0; j < cols; j++)
            if (vc[j])
                for (int i = 0; i < rows; i++)
                    matrix[i][j] = 0;
    }
};