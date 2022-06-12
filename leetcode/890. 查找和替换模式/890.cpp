class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sz = s.size();
        vector<int> v1(256, -1);
        vector<int> v2(256, -1);
        for (int i = 0; i < sz; i++)
        {
            if (v1[s[i]] == -1)
                v1[s[i]] = t[i];
            else
                if (v1[s[i]] != t[i])
                    return false;
            if (v2[t[i]] == -1)
                v2[t[i]] = s[i];
            else
                if (v2[t[i]] != s[i])
                    return false;
        }
        return true;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> v;
        for (string& s : words)
        {
            if (isIsomorphic(s, pattern))
                v.push_back(s);
        }
        return v;
    }
};