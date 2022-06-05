class Solution {
public:
    Solution(double radius, double x_center, double y_center)
        :_radius(radius),
        _x_center(x_center),
        _y_center(y_center)
    {
        e.seed(time(0));
        ans.resize(2);
    }

    vector<double> randPoint() {
        std::uniform_real_distribution<double> u(0, _radius * _radius);
        // ×ó±ÕÓÒ±ÕÇø¼ä
        std::uniform_real_distribution<double> a(0, 360);
        double radius = sqrt(u(e));
        double angle = a(e);
        ans[0] = _x_center + radius * cos(angle * 3.14159265 / 180);
        ans[1] = _y_center + radius * sin(angle * 3.14159265 / 180);
        return ans;
    }
private:
    double _radius;
    double _x_center;
    double _y_center;
    std::default_random_engine e;
    vector<double> ans;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */