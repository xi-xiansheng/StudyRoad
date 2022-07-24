class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        _size = size;
    }

    double next(int val) {
        sum += val;
        if (q.size() == _size)
        {
            sum -= q.front();
            q.pop();
        }
        q.push(val);
        return sum / q.size();
    }
private:
    queue<int> q;
    int _size;
    double sum = 0;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */