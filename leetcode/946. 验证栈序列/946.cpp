class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int sz = pushed.size();
        int index1 = 0, index2 = 0;
        while (index1 < sz && index2 < sz)
        {
            if (index1 < sz)
                st.push(pushed[index1++]);
            while (!st.empty() && index2 < sz)
            {
                if (popped[index2] == st.top())
                {
                    st.pop();
                    index2++;
                }
                else
                    break;
            }
        }
        while (index2 < sz)
        {
            if (popped[index2] == st.top())
            {
                st.pop();
                index2++;
            }
            else
                break;
        }
        return st.empty();
    }
};