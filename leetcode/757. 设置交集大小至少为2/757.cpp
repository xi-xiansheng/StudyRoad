class Solution {
public:
    struct bs {
        bool operator()(vector<int> interval1, vector<int> interval2)
        {
            if (interval1[1] < interval2[1] ||
                (interval1[1] == interval2[1] && interval1[0] > interval2[0]))
                return true;
            return false;
        }
    };

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end(), bs());
        int ans = 0;
        int x = -1, y = -1;
        for (auto interval : intervals)
        {
            if (interval[0] > y)
            {
                ans += 2;
                y = interval[1];
                x = y - 1;
            }
            else if (interval[0] > x)
            {
                x = y;
                y = interval[1];
                ans += 1;
            }
        }
        return ans;
    }
};