class Solution {
public:

    void dfs(int h, string s, set<string>& st)
    {
        if (h == s.size() - 1)
        {
            st.insert(s);
            return;
        }
        for (int i = h; i < s.size(); ++i)
        {
            std::swap(s[i], s[h]);
            dfs(h + 1, s, st);
            std::swap(s[i], s[h]);
        }
    }


    vector<string> Permutation(string str) {
        set<string> st;
        dfs(0, str, st);
        return vector<string>(st.begin(), st.end());
    }
};