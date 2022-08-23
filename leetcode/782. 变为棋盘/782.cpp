class Solution {
public:
    int movesToChessboard(vector<vector<int>>& board) {
        int n = board.size(), rowSum = 0, colSum = 0, rowDiff = 0, colDiff = 0;

        for (int i = 0; i < n; i++)
        {
            /**
            ***一个矩形的四个顶点只有三种情况
            ***要么四个0，要么四个1，要么两个0两个1
            ***那么四个顶点异或在一起一定是0
            ***所以我们判断只要异或出了1，一定是不对的，直接返回-1
            **/
            for (int j = 0; j < n; j++)
            {
                if (board[0][0] ^ board[i][0] ^ board[i][j] ^ board[0][j])   return -1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            colSum += board[i][0];
            rowSum += board[0][i];
            rowDiff += (board[0][i] == i % 2);
            colDiff += (board[i][0] == i % 2);
        }
        if (rowSum < n / 2 || rowSum >(n + 1) / 2)  return -1;
        if (colSum < n / 2 || colSum >(n + 1) / 2)  return -1;

        if (n % 2)
        {
            // n是奇数，必须得到偶数个错位数
            if (colDiff % 2) colDiff = n - colDiff;
            if (rowDiff % 2) rowDiff = n - rowDiff;
        }
        else
        {
            // 我们默认是跟   1010... 比较
            // 假设棋盘排列为 0101... 这本身就是正确的棋盘排列
            colDiff = std::min(n - colDiff, colDiff);
            rowDiff = std::min(n - rowDiff, rowDiff);
        }
        return (colDiff + rowDiff) / 2;
    }
};