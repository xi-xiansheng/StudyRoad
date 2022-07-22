class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        // 根据容斥原理，答案为：ans = x * n + y * m - 2 * x * y 
        vector<bool> rows(m, false);
        vector<bool> cols(n, false);
        int x = 0, y = 0;
        for (auto& indice : indices)
        {
            rows[indice[0]] = !rows[indice[0]];
            cols[indice[1]] = !cols[indice[1]];
        }
        for (int i = 0; i < m; i++)
        {
            if (rows[i])
                x++;
        }
        for (int i = 0; i < n; i++)
        {
            if (cols[i])
                y++;
        }
        return x * n + y * m - 2 * x * y;
    }
};