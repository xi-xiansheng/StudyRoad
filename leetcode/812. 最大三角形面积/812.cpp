class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double ans = 0;
        //º£Â×¹«Ê½
        double a = 0;
        double b = 0;
        double c = 0;
        double p = 0;
        int sz = points.size();
        for (int i = 0; i < sz - 2; i++)
        {
            for (int j = i + 1; j < sz - 1; j++)
            {
                for (int k = j + 1; k < sz; k++)
                {
                    a = sqrt(pow(points[i][0] - points[j][0], 2) + pow(points[i][1] - points[j][1], 2));
                    b = sqrt(pow(points[j][0] - points[k][0], 2) + pow(points[j][1] - points[k][1], 2));
                    c = sqrt(pow(points[k][0] - points[i][0], 2) + pow(points[k][1] - points[i][1], 2));
                    p = (a + b + c) / 2;
                    double res = sqrt(p * (p - a) * (p - b) * (p - c));
                    if (ans < res)
                        ans = res;
                }
            }
        }
        return ans;
    }
};