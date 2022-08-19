class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans = 0;
        for (int i = 0, sz = startTime.size(); i < sz; i++)
        {
            if (startTime[i] <= queryTime && queryTime <= endTime[i])
                ans++;
        }
        return ans;
    }
};