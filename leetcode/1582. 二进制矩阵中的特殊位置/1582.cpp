class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        unordered_map<int, int> rows;
        unordered_map<int, int> cols;
        for (int i = 0, _rows = mat.size(); i < _rows; i++)
        {
            int sum = 0;
            for (int j = 0, _cols = mat[i].size(); j < _cols; j++)
            {
                cols[j] += mat[i][j];
                sum += mat[i][j];
            }
            rows[i] += sum;
        }
        for (auto& [row, num] : rows)
        {
            if (num != 1)    continue;
            for (auto& [col, size] : cols)
            {
                if (size == 1 && mat[row][col] == 1)
                {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};