struct Vector {
    Vector(const vector<int>& pointa, const vector<int>& pointb)
        :x(pointa[0] - pointb[0]),
        y(pointa[1] - pointb[1])
    {

    }

    double cross(Vector v)
    {
        return std::sqrt(std::pow(x * v.y - y * v.x, 2));
    }

    double x;
    double y;
};
double DiatancePL(const vector<int>& pointa, const vector<int>& pointb, const vector<int>& pointc)
{
    Vector ab(pointa, pointb);
    Vector ac(pointa, pointc);
    return ab.cross(ac) / std::sqrt(ab.x * ab.x + ab.y * ab.y);
}
class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        if (points[0][0] == points[1][0] && points[0][1] == points[1][1])
            return false;
        if (points[1][0] == points[2][0] && points[1][1] == points[2][1])
            return false;
        if (points[0][0] == points[2][0] && points[0][1] == points[2][1])
            return false;
        // 利用点到直线的距离是否为0
        return DiatancePL(points[0], points[1], points[2]);
    }
};