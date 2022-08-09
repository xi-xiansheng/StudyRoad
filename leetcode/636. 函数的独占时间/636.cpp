class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n);
        stack<pair<int, int>> st;
        for (auto& s : logs)
        {
            int cur = -1;
            int index = 0;
            bool flag = false;
            while (s[index] != ':')
            {
                index++;
            }
            cur = stoi(string(s.begin(), s.begin() + index++));
            if (s[index] == 's')
            {
                flag = true;
            }
            while (s[index++] != ':')
            {

            }
            int time = stoi(string(s.begin() + index, s.end()));


            auto p = make_pair(cur, time);
            if (flag)
            {
                if (!st.empty())
                {
                    ans[st.top().first] += p.second - st.top().second;
                    st.top().second = p.second;
                }
                st.push(p);
            }
            else
            {
                ans[st.top().first] += p.second - st.top().second + 1;
                st.pop();
                if (!st.empty())
                {
                    st.top().second = p.second + 1;
                }
            }
        }
        return ans;
    }
};