class Solution {
public:

    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> _arrays(n, vector<int>(n, 1));
        int index = 0;
        int val = 1;
        while (index * 2 < n)
        {
            for (int j = index; j < n - index; j++)
            {
                _arrays[index][j] = val++;
            }
            for (int i = index + 1; i < n - index; i++)
            {
                _arrays[i][n - 1 - index] = val++;
            }
            for (int j = n - 1 - index - 1; j >= index; j--)
            {
                _arrays[n - 1 - index][j] = val++;
            }
            for (int i = n - 1 - index - 1; i > index; i--)
            {
                _arrays[i][index] = val++;
            }
            index++;
        }
        return _arrays;
    }
};