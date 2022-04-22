class Solution {
public:
    bool GetStatus(bitset<9>& cols,
        bitset<2 * 9 - 1>& slashs,
        bitset<2 * 9 - 1>& backslashs,
        int x, int y)
    {
        return cols[y] | slashs[x + y] | backslashs[x - y + sz - 1];
    }

    void QuennFill(bitset<9>& cols,
        bitset<2 * 9 - 1>& slashs,
        bitset<2 * 9 - 1>& backslashs, int index)
    {
        //int sz = col.size();
        if (sz <= index)
        {
            return;
        }
        for (int y = 0; y < sz; y++)
        {
            if (!GetStatus(cols, slashs, backslashs, index, y))
            {
                cols[y] = 1;
                slashs[index + y] = 1;
                backslashs[index - y + sz - 1] = 1;
                if (index == sz - 1)
                {
                    count++;
                }
                QuennFill(cols, slashs, backslashs, index + 1);
                cols[y] = 0;
                slashs[index + y] = 0;
                backslashs[index - y + sz - 1] = 0;
            }
        }
    }


    int totalNQueens(int n) {
        if (n == 0)
            return 0;
        /*switch(n)
        {
            case 1 : return 1;
            case 2 : return 0;
            case 3 : return 0;
            case 4 : return 2;
            case 5 : return 10;
            case 6 : return 4;
            case 7 : return 40;
            case 8 : return 92;
            case 9 : return 352;
        }*/

        count = 0;
        sz = n;
        bitset<9> cols;
        bitset<2 * 9 - 1> slashs;
        bitset<2 * 9 - 1> backslashs;
        QuennFill(cols, slashs, backslashs, 0);
        return count;
    }
private:
    int count;
    int sz;
};