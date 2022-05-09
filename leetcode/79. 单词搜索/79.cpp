class Solution {
public:
    bool _haspath(vector<vector<char> >& matrix, string& word, int index, int row, int col)
    {
        if (word[index] == '\0')
            return true;
        if (row < 0 || col < 0 || row >= matrix.size() || col >= matrix[0].size() || matrix[row][col] < 0 || matrix[row][col] != word[index])
            return false;
        matrix[row][col] = -matrix[row][col];
        if (_haspath(matrix, word, index + 1, row - 1, col) ||
            _haspath(matrix, word, index + 1, row + 1, col) ||
            _haspath(matrix, word, index + 1, row, col - 1) ||
            _haspath(matrix, word, index + 1, row, col + 1))
            return true;
        matrix[row][col] = -matrix[row][col];
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == word[0])
                    if (_haspath(board, word, 0, i, j))
                        return true;
            }
        }
        return false;
    }
};