/*class Solution {
public:
    int ToLeft(const vector<int>& height, int index)
    {
        if (index <= 0)
            return 0;
        int mleft = index - 1;
        for (int i = index - 1; i >= 0; i--)
        {
            if (height[i] >= height[mleft])
            {
                mleft = i;
            }
        }
        if (height[mleft] == 0)
            return 0;
        int min = height[index] < height[mleft] ? height[index] : height[mleft];
        int sum = min * (index - mleft - 1);
        for (int i = mleft + 1; i < index; i++)
        {
            sum -= height[i];
        }
        return sum + ToLeft(height, mleft);
    }
    int ToRight(const vector<int>& height, int index)
    {
        if (index >= height.size() - 1)
            return 0;
        int mright = index + 1;
        for (int i = index + 1; i < height.size(); i++)
        {
            if (height[i] >= height[mright])
            {
                mright = i;
            }
        }
        if (height[mright] == 0)
            return 0;
        int min = height[index] < height[mright] ? height[index] : height[mright];
        int sum = min * (mright - index - 1);
        for (int i = index + 1; i < mright; i++)
        {
            sum -= height[i];
        }
        return sum + ToRight(height, mright);
    }
    int trap(vector<int>& height) {
        int index = 0;
        for (int i = 0; i < height.size(); i++)
        {
            if (height[i] >= height[index])
            {
                index = i;
            }
        }
        return ToLeft(height, index) + ToRight(height, index);
    }
};*/
class Solution {
public:
    int ToLeft(const vector<int>& height)
    {
        int sum = 0;
        int cur = st.top();
        st.pop();
        int prev;
        while (!st.empty())
        {
            prev = st.top();
            st.pop();
            int min = height[cur] < height[prev] ? height[cur] : height[prev];
            sum += min * (cur - prev - 1);
            cur--;
            while (cur > prev)
            {
                sum -= height[cur];
                cur--;
            }
        }
        return sum;
    }
    int ToRight(const vector<int>& height)
    {
        int sum = 0;
        int cur = st.top();
        st.pop();
        int prev;
        while (!st.empty())
        {
            prev = st.top();
            st.pop();
            int min = height[cur] < height[prev] ? height[cur] : height[prev];
            sum += min * (prev - cur - 1);
            cur++;
            while (cur < prev)
            {
                sum -= height[cur];
                cur++;
            }
        }
        return sum;
    }
    int trap(vector<int>& height) {
        int index = 0;
        //×ó°ë±ß
        st.push(0);
        for (int i = 1; i < height.size(); i++)
        {
            if (height[i] >= height[st.top()])
            {
                index = i;
                st.push(i);
            }
        }
        int sum = ToLeft(height);
        //ÓÒ°ë±ß
        st.push(height.size() - 1);
        for (int i = (int)height.size() - 2; i >= index; i--)
        {
            if (height[i] >= height[st.top()])
            {
                st.push(i);
            }
        }
        return sum + ToRight(height);
    }
private:
    stack<int> st;
};
