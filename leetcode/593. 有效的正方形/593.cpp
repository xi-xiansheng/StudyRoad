class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int CenterX = p1[0] + p2[0] + p3[0] + p4[0];
        int CenterY = p1[1] + p2[1] + p3[1] + p4[1];
        auto f = [&](const vector<int>& v) { int x = v[0] * 4 - CenterX;
        int y = v[1] * 4 - CenterY;
        return vector<int>{ x, y }; };
        vector<vector<int>> v{ f(p1), f(p2), f(p3), f(p4) };
        auto vhash = [](const vector<int>& p) ->int { return p[0] * 13131 + p[1]; };
        unordered_set<vector<int>, decltype(vhash)> s(v.begin(), v.end(), 0, vhash);
        for (auto& p : v)
        {
            s.insert(p);
        }
        if (s.size() < 4)
            return false;
        for (auto& p : s)
        {
            if (s.count({ -p[1], p[0] }) == 0)
                return false;
        }
        return true;
    }
};