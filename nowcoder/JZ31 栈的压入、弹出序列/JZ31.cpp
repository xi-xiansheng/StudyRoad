class Solution {
    //思路：
    //
public:
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> st;
        //用于遍历vector 
        size_t pushi = 0, popj = 0;
        while (pushi < pushV.size())
        {
            st.push(pushV[pushi]);
            //如果栈顶元素与 popj 指向的popV的数据相同，依次出栈直至不相同
            while (!st.empty() && st.top() == popV[popj])
            {
                st.pop();
                popj++;
            }
            pushi++;
        }

        if (st.empty())
        {
            return true;
        }
        return false;
    }
};