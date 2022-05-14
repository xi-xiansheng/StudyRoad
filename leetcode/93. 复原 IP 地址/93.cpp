class Solution {
public:
    bool Check(const string& s)
    {
        if (s[0] == '0')
        {
            if (s.size() == 1)
                return true;
            return false;
        }
        if (s.size() > 3)
            return false;
        int ret = stoi(s);
        return ret <= 255;
    }
    void dfs(const string& s, int start)
    {
        int sz = s.size();
        if (start >= sz && tmp.size() == 4)
        {
            string ss;
            for (int i = 0; i < 3; i++)
            {
                ss += tmp[i];
                ss += '.';
            }
            ss += tmp[3];
            ans.push_back(ss);
            return;
        }
        else if (start < sz && tmp.size() == 4)
        {
            return;
        }
        for (int i = 1; i <= 3; i++)
        {
            if (start + i <= sz)
            {
                string ss(s.begin() + start, s.begin() + start + i);
                if (Check(ss))
                {
                    tmp.push_back(ss);
                    dfs(s, start + i);
                    tmp.pop_back();
                }
                else
                    return;
            }
            else
                return;
        }
    }

    vector<string> restoreIpAddresses(string s) {
        dfs(s, 0);
        return ans;
    }
private:
    vector<string> ans;
    vector<string> tmp;
};