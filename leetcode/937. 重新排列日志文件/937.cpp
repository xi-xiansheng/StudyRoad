struct _Compare
{
    bool operator()(const string s1, const string s2)
    {
        int i = 0, j = 0;
        int sz1 = s1.size();
        int sz2 = s2.size();
        while (i < sz1)
        {
            if (s1[i++] == ' ')
                break;
        }
        while (j < sz2)
        {
            if (s2[j++] == ' ')
                break;
        }
        while (i < sz1 && j < sz2)
        {
            if (s1[i] != s2[j])
                return s1[i] < s2[j];
            i++;
            j++;
        }
        if (i == sz1 && j == sz2)
        {
            i = j = 0;
            while (i < sz1 && j < sz2)
            {
                if (s1[i] != s2[j])
                    return s1[i] < s2[j];
                i++;
                j++;
            }
        }
        return s1[i] < s2[j];
    }
};

class Solution {
public:
    bool Iscid(const string& s)
    {
        int i = 0;
        int sz = s.size();
        while (i < sz)
        {
            if (s[i++] == ' ')
                break;
        }
        return isalpha(s[i]);
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        int sz = logs.size();
        int nid = sz - 1;
        int cid = sz - 1;
        while (cid >= 0)
        {
            if (Iscid(logs[cid]))
            {
                nid = cid - 1;
                while (nid >= 0 && Iscid(logs[nid]))
                {
                    nid--;
                }
                if (nid == -1)
                    break;
                else
                    std::swap(logs[cid], logs[nid]);
            }
            cid--;
        }
        cid++;
        std::sort(logs.begin(), logs.begin() + cid, _Compare());
        return logs;
    }
};