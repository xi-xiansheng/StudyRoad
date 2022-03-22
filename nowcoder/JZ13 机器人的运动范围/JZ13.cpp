class Solution {
public:
    int Count(vector<vector<int>>& count, int threshold, int rows, int cols)
    {
        //递归求和
        if (rows >= count.size() || cols >= count[0].size() || count[rows][cols] == 0 || (rows / 10 + rows % 10 + cols / 10 + cols % 10) > threshold)
            return 0;
        count[rows][cols] = 0;
        return 1 + Count(count, threshold, rows, cols + 1)
            + Count(count, threshold, rows + 1, cols);
    }

    int movingCount(int threshold, int rows, int cols) {
        //二维数组创建
        vector<vector<int>> count;
        count.resize(rows);
        for (size_t i = 0; i < rows; i++)
        {
            count[i].resize(cols);
        }
        //赋值
        for (size_t i = 0; i < rows; i++)
        {
            for (size_t j = 0; j < cols; j++)
            {
                count[i][j] = 1;
            }
        }
        return Count(count, threshold, 0, 0);
    }
};