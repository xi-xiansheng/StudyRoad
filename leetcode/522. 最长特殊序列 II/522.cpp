class Solution {
public:
    bool SubString(const string& s1, const string& s2)
    {
        // s2 ЮЊзгађСа
        int cur1 = 0;
        int cur2 = 0;
        int sz1 = s1.size();
        int sz2 = s2.size();
        if (sz1 < sz2)
            return false;
        while (cur1 < sz1 && cur2 < sz2)
        {
            while (cur1 < sz1 && s1[cur1] != s2[cur2])
            {
                cur1++;
            }
            if (s1[cur1] == s2[cur2])
            {
                cur1++;
                cur2++;
            }
        }
        return sz2 == cur2;
    }

    int findLUSlength(vector<string>& strs) {
        int sz = strs.size();
        int len = 0;
        for (int i = 0; i < sz; i++)
        {
            bool flag = false;
            int _len = 0;
            for (int j = 0; j < sz; j++)
            {
                if (i == j)
                    continue;
                if (SubString(strs[j], strs[i]) == true)
                {
                    flag = true;
                    break;
                }
                _len = _len > strs[i].size() ? _len : strs[i].size();
            }
            if (flag == false)
                len = len > _len ? len : _len;
        }
        return len == 0 ? -1 : len;
    }
};