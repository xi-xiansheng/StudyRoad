class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (const auto& str : tokens)
        {
            int left, right;
            if (str == "+")
            {
                right = st.top();
                st.pop();
                left = st.top();
                st.pop();
                st.push(left + right);
            }
            else if (str == "-")
            {
                right = st.top();
                st.pop();
                left = st.top();
                st.pop();
                st.push(left - right);
            }
            else if (str == "*")
            {
                right = st.top();
                st.pop();
                left = st.top();
                st.pop();
                st.push(left * right);
            }
            else if (str == "/")
            {
                right = st.top();
                st.pop();
                left = st.top();
                st.pop();
                st.push(left / right);
            }
            else
            {
                st.push(stoi(str));
            }
        }
        return st.top();
    }
};