class MyQueue {
public:
    MyQueue() {

    }
    //若用于出队列的栈不为空，则需先转移数据，以保持顺序
    void push(int x) {

        while (!st_pop.empty())
        {
            st_push.push(st_pop.top());
            st_pop.pop();
        }
        st_push.push(x);
    }
    //出队列同理
    int pop() {
        while (!st_push.empty())
        {
            st_pop.push(st_push.top());
            st_push.pop();
        }
        int val = st_pop.top();
        st_pop.pop();
        return val;
    }

    int peek() {
        while (!st_push.empty())
        {
            st_pop.push(st_push.top());
            st_push.pop();
        }
        return st_pop.top();
    }

    //当栈均为空，则队列为空
    bool empty() {
        return st_push.empty() && st_pop.empty();
    }

    
    stack<int> st_push;
    stack<int> st_pop;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */