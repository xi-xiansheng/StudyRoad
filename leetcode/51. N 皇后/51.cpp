class Solution {
public:
    bool GetStatus(const vector<string>& vs, int x, int y)
    {
        int sz = vs[0].size();
        //行
        for (int i = 0; i < sz; i++)
        {
            if (vs[x][i] == 'Q')
            {
                return false;
            }
        }
        //列
        for (int i = 0; i < sz; i++)
        {
            if (vs[i][y] == 'Q')
            {
                return false;
            }
        }
        //对角
        //左上
        for (int i = x, j = y; i >= 0 && j >= 0; i--, j--)
        {
            if (vs[i][j] == 'Q')
            {
                return false;
            }
        }
        //右上
        for (int i = x, j = y; i >= 0 && j < sz; i--, j++)
        {
            if (vs[i][j] == 'Q')
            {
                return false;
            }
        }
        //左下
        for (int i = x, j = y; i < sz && j >= 0; i++, j--)
        {
            if (vs[i][j] == 'Q')
            {
                return false;
            }
        }
        //右下
        for (int i = x, j = y; i < sz && j < sz; i++, j++)
        {
            if (vs[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    void Fill(vector<string>& vs, int index)
    {
        int sz = vs[0].size();
        if (index >= sz)
        {
            return;
        }

        for (int i = 0; i < sz; i++)
        {
            if (GetStatus(vs, index, i))
            {
                vs[index][i] = 'Q';
                Fill(vs, index + 1);
                if (index == sz - 1)
                {
                    vvs.push_back(vs);
                }
                vs[index][i] = '.';
            }
        }
        return;
    }

    void Initia(vector<string>& vs)
    {
        int n = vs[0].size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                vs[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> vs;
        vs.resize(n);
        //初始化
        for (int i = 0; i < n; i++)
        {
            vs[i].resize(n);
        }
        Initia(vs);
        Fill(vs, 0);
        return vvs;
    }
private:
    vector<vector<string>> vvs;
};