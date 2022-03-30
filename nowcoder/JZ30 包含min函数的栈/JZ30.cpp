class Solution {
public:
    void push(int value)
    {
        st.push(value);
        if (_min.empty())
            _min.push(value);
        else
        {
            if (_min.top() >= value)
                _min.push(value);
        }
    }
    void pop() {
        if (st.top() == _min.top())
            _min.pop();
        st.pop();
    }
    int top() {
        return st.top();
    }
    int min() {
        return _min.top();
    }

    stack<int> st;
    stack<int> _min;
};