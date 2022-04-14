class MinStack {
public:
    MinStack() {

    }

    void push(int val) {
        //若栈为空，则均入栈；若比最小栈的栈顶元素小或等，则入最小栈
        if (st.empty() || val <= min_st.top())
        {
            min_st.push(val);
        }
        st.push(val);
    }

    void pop() {
        //若栈顶元素小于或等于最小栈栈顶元素，则均出栈
        if (st.top() <= min_st.top())
        {
            min_st.pop();
        }
        st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_st.top();
    }

    //创建两个栈
    stack<int> st;      //用于保存所有入栈元素
    stack<int> min_st;  //用于保存当前栈中最小元素，即该栈栈顶元素
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */










