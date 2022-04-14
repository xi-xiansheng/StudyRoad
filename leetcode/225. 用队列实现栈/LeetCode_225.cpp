class MyStack {

    //保证其中一个队列为空
public:
    MyStack() {

    }

    void push(int x)
    {
        if (!_q1.empty())
        {
            while (!_q2.empty())
            {
                _q1.push(_q2.front());
                _q2.pop();
            }
            _q1.push(x);
        }
        else
        {
            while (!_q1.empty())
            {
                _q2.push(_q1.front());
                _q1.pop();
            }
            _q2.push(x);
        }

    }

    //转移前 n - 1 个数据，删除最后一个数据即可
    int pop() {
        if (_q1.empty())
        {
            while (_q2.size() != 1)
            {
                _q1.push(_q2.front());
                _q2.pop();
            }
            int val = _q2.front();
            _q2.pop();
            return val;
        }
        else
        {
            while (_q1.size() != 1)
            {
                _q2.push(_q1.front());
                _q1.pop();
            }
            int val = _q1.front();
            _q1.pop();
            return val;
        }

    }

    //返回最后一个数据即可
    int top() {
        if (_q1.empty())
        {
            return _q2.back();
        }
        else
        {
            return _q1.back();
        }
    }

    bool empty() {
        return _q1.empty() && _q2.empty();
    }
    // 分别用来出/入数据
    queue<int> _q1;
    queue<int> _q2;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */