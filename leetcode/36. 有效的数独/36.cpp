class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> m;
        //行
        for (int i = 0; i < 9; i++)
        {
            m.clear();
            for (int j = 0; j < 9; j++)
            {
                if (board[i][j] == '.')
                    continue;
                m[board[i][j]] += 1;
                if (m[board[i][j]] > 1)
                    return false;
            }
        }
        //列
        for (int i = 0; i < 9; i++)
        {
            m.clear();
            for (int j = 0; j < 9; j++)
            {
                if (board[j][i] == '.')
                    continue;
                m[board[j][i]] += 1;
                if (m[board[j][i]] > 1)
                    return false;
            }
        }
        //每小格
        for (int i = 0; i < 9; i += 3)
        {
            for (int j = 0; j < 9; j += 3)
            {
                m.clear();
                for (int x = 0; x < 3; x++)
                {
                    for (int y = 0; y < 3; y++)
                    {
                        if (board[i + x][j + y] == '.')
                            continue;
                        m[board[i + x][j + y]] += 1;
                        if (m[board[i + x][j + y]] > 1)
                            return false;
                    }
                }
            }
        }
        return true;
    }
};