class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> newimterval;
        int index = 0;
        vector<int> interval = { -1, -1 };
        int sz = intervals.size();
        std::sort(intervals.begin(), intervals.end());
        while (index < sz)
        {
            interval = intervals[index];
            while (index + 1 < sz)
            {
                if (interval[1] >= intervals[index + 1][0])
                {
                    interval[1] = interval[1] > intervals[index + 1][1] ? interval[1] : intervals[index + 1][1];
                    index++;
                }
                else
                    break;
            }
            newimterval.push_back(interval);
            index++;
        }
        return newimterval;
    }
};