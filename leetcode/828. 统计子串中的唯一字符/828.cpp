class Solution {
public:
    int uniqueLetterString(string s) {
        vector<int> prev(26, -1);
        vector<int> cur(26, -1);
        int ans = 0;
        for (int i = 0, sz = s.size(); i < sz; i++)
        {
            int index = s[i] - 'A';
            if (cur[index] > -1)
            {
                ans += (cur[index] - prev[index]) * (i - cur[index]);
            }
            prev[index] = cur[index];
            cur[index] = i;
        }
        for (int i = 0, len = s.size(); i < 26; i++)
        {
            if (cur[i] > -1)
            {
                ans += (len - cur[i]) * (cur[i] - prev[i]);
            }
        }
        return ans;
    }
};