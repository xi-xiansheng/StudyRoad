class Solution {
public:
    int longestValidParentheses(string s) {
        //ջ
        stack<int> st;
        st.push(-1);
        int max = 0;
        int cur = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if (st.empty())
                {
                    st.push(i);
                }
                else
                {

                    cur = i - st.top();
                    if (cur > max)
                    {
                        max = cur;
                    }
                }
            }
        }
        return max;
    }
};