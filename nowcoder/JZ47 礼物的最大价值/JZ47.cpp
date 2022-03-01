class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param grid int整型vector<vector<>>
     * @return int整型
     */
    int Sum(vector<vector<int> >& grid, vector<vector<int> >& count, int x, int y)
    {
        //满足条件之一，即无需递归
        if (x == count.size() - 1 || y == count[0].size() - 1 || count[x][y] > 0)
            return count[x][y];
        int max1 = Sum(grid, count, x + 1, y);
        int max2 = Sum(grid, count, x, y + 1);
        count[x][y] = max1 > max2 ? grid[x][y] + max1 : grid[x][y] + max2;
        //count[x][y] += count[x + 1][y] > count[x][y + 1] ? count[x + 1][y] + grid[x][y] : count[x][y + 1] + grid[x][y];
        return count[x][y];
    }

    int maxValue(vector<vector<int> >& grid) {
        // write code here
        //空间换时间
        //创建二维数组，均赋值为 0
        vector<vector<int> > count;
        count.resize(grid.size() + 1);
        for (auto& e : count)
        {
            e.resize(grid[0].size() + 1);
            for (auto& ee : e)
            {
                ee = 0;
            }
        }
        //计算
        return Sum(grid, count, 0, 0);
    }
};