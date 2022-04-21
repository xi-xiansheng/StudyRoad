class Solution {
public:

    bitset<9> GetStatus(int x, int y)
    {
        return rows[x] | cols[y] | grids[x / 3][y / 3];
    }

    vector<int> GetNext(vector<vector<char>>& board)
    {
        vector<int>vc = { -1, -1 };
        int count = 10;
        for (int x = 0; x < 9; x++)
        {
            for (int y = 0; y < 9; y++)
            {
                if (board[x][y] == '.')
                {
                    int _count = 9 - GetStatus(x, y).count();
                    if (_count == 0)
                    {
                        vc[0] = x;
                        vc[1] = y;
                        return vc;
                    }
                    if (_count < count)
                    {
                        count = _count;
                        vc[0] = x;
                        vc[1] = y;
                    }
                }
            }
        }
        return vc;
    }

    bool FillNum(vector<vector<char>>& board)
    {
        vector<int> pos = GetNext(board);
        if (pos[0] == -1)
            return true;
        int x = pos[0];
        int y = pos[1];
        bitset<9> Status = GetStatus(x, y);
        if (Status.count() == 9 && board[x][y] == '.')
            return false;
        for (int i = 0; i < 9; i++)
        {
            if (Status[i] == 0)
            {
                rows[x][i] = 1;
                cols[y][i] = 1;
                grids[x / 3][y / 3][i] = 1;
                board[x][y] = i + '1';
                if (FillNum(board))
                {
                    return true;
                }
                else
                {
                    rows[x][i] = 0;
                    cols[y][i] = 0;
                    grids[x / 3][y / 3][i] = 0;
                    board[x][y] = '.';
                }
            }
        }
        return false;
    }


    void solveSudoku(vector<vector<char>>& board)
    {
        //初始化位图
        rows.resize(9);
        cols.resize(9);
        grids.resize(3);
        for (int i = 0; i < 3; i++)
        {
            grids[i].resize(3);
        }
        for (int x = 0; x < 9; x++)
        {
            for (int y = 0; y < 9; y++)
            {
                if (board[x][y] == '.')
                    continue;
                rows[x][board[x][y] - '1'] = 1;
                cols[y][board[x][y] - '1'] = 1;
                grids[x / 3][y / 3][board[x][y] - '1'] = 1;
            }
        }
        //解数独
        FillNum(board);
    }

private:
    vector<bitset<9>> rows;
    vector<bitset<9>> cols;
    vector<vector<bitset<9>>> grids;
};