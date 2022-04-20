class Solution {
public:
    void rotate(vector<vector<int>>& matrix, int index) {
        if (index >= matrix.size() / 2)
            return;
        int sz = matrix[0].size();
        for (int i = index; i < sz - index - 1; i++)
        {
            int tmp = matrix[index][i];
            matrix[index][i] = matrix[sz - i - 1][index];
            matrix[sz - i - 1][index] = matrix[sz - 1 - index][sz - 1 - i];
            matrix[sz - 1 - index][sz - 1 - i] = matrix[i][sz - 1 - index];
            matrix[i][sz - 1 - index] = tmp;
        }
        rotate(matrix, index + 1);
    }

    void rotate(vector<vector<int>>& matrix) {
        rotate(matrix, 0);
    }
};