class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<char> vc;
        for (auto e : strs[0])
        {
            vc.push_back(e);
        }
        int big = 0;
        char ch = '\0';
        for (auto e : strs)
        {
            for (int i = 0; i < vc.size() && vc.size(); i++)
            {
                if (e[i] == vc[i])
                    continue;
                else
                    vc.resize(i);
            }
        }
        string s;
        for (auto e : vc)
        {
            s += e;
        }
        return s;
    }
};