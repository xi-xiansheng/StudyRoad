struct Squares
{
    int left;
    int right;
    int height;
    Squares(int _left, int _right, int _height) :
        left(_left),
        right(_right),
        height(_height) {
    }
};

class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        vector<int> ans;
        vector<Squares> vs;
        int max = 0;
        for (auto e : positions)
        {
            int left = e[0];
            int right = e[0] + e[1] - 1;
            int height = e[1];
            int _max = 0;
            for (Squares s : vs)
            {
                // ÎÞ½»¼¯
                if (s.left > right || s.right < left)
                    continue;
                _max = std::max(_max, s.height);
            }
            height += _max;
            Squares ns(left, right, height);
            vs.push_back(ns);
            max = std::max(max, height);
            ans.push_back(max);
        }
        return ans;
    }
};