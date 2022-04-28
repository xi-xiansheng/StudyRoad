/*class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        std::sort(intervals.begin(), intervals.end());
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
};*/
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        //intervals.push_back(newInterval);
        //std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        int index = 0;
        int sz = intervals.size();
        int falg = 0;
        while (index < sz)
        {
            if (intervals[index][1] < newInterval[0])
            {
                ans.push_back(intervals[index]);
                index++;
            }
            else
            {
                falg = 1;
                vector<int> res = { -1, -1 };
                res[0] = newInterval[0] < intervals[index][0] ? newInterval[0] : intervals[index][0];
                while (index < sz)
                {
                    if (intervals[index][1] < newInterval[1])
                    {
                        index++;
                    }
                    else
                    {
                        if (intervals[index][0] <= newInterval[1])
                        {
                            res[1] = intervals[index][1];
                            index++;
                        }
                        else
                            res[1] = newInterval[1];
                        break;
                    }
                }
                if (index == sz)
                {
                    res[1] = newInterval[1] > intervals[sz - 1][1] ? newInterval[1] : intervals[sz - 1][1];
                }
                ans.push_back(res);
                while (index < sz)
                {
                    ans.push_back(intervals[index]);
                    index++;
                }
                break;
            }
        }
        if (falg == 0)
            ans.push_back(newInterval);
        return ans;
    }
};