/*class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // 暴力求解
        for(int i = 0, sz = prices.size(); i < sz; i++)
        {
            int j = i + 1;
            while(j < sz && prices[j] > prices[i])
            {
                j++;
            }
            if(j < sz)  prices[i] = prices[i] - prices[j];
        }
        return prices;
    }
};*/
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        // 单调栈
        stack<int> st;
        st.push(0);
        for (int i = 1, sz = prices.size(); i < sz; i++)
        {
            if (prices[i] > prices[st.top()])    st.push(i);
            else
            {
                while (!st.empty())
                {
                    int index = st.top();
                    if (prices[index] < prices[i]) break;
                    st.pop();
                    prices[index] = prices[index] - prices[i];
                }
                st.push(i);
            }
        }
        return prices;
    }
};