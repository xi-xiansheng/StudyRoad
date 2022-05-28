class Solution {
public:
    string removeOuterParentheses(string s) {

        int sz = s.size();
        int index = 0;
        vector<string> vs;
        stack<char> st;
        string ans;
        string tmp;
        while (index < sz)
        {
            tmp += s[index];
            if (s[index] == '(')
                st.push('(');
            else
                st.pop();
            if (st.size() == 0)
            {
                vs.push_back(tmp);
                tmp = "";
            }
            index++;
        }
        for (string& ss : vs)
        {
            int len = ss.size();
            for (int i = 1; i < len - 1; i++)
                ans += ss[i];
        }
        return ans;
    }
};