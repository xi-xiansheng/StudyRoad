/*class Solution {
public:
    int MaxPth(vector<vector<int>>& triangle, int i, int j)
    {
        int sz = triangle.size();
        if(i >= sz)
            return 0;
        int ans1 = triangle[i][j] + MaxPth(triangle, i + 1, j);
        int ans2 = triangle[i][j + 1] + MaxPth(triangle, i + 1, j + 1);

        return ans1 < ans2 ? ans1 : ans2;
    }


    int minimumTotal(vector<vector<int>>& triangle) {
        return MaxPth(triangle, 1, 0) + triangle[0][0];
    }
};*/
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz = triangle.size();
        for (int i = sz - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }
        return triangle[0][0];
    }
};