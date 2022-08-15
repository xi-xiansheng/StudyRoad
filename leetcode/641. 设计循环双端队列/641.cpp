class MyCircularDeque {
public:
    MyCircularDeque(int k)
        :_head(0),
        _tail(0),
        _sz(k + 1)
    {
        _v.resize(k + 1);
    }

    bool insertFront(int value) {
        if (isFull())
            return false;
        _head = (_head + _sz - 1) % _sz;
        _v[_head] = value;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;
        _v[_tail] = value;
        _tail = (_tail + 1) % _sz;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;
        _head = (_head + 1) % _sz;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;
        _tail = (_tail - 1 + _sz) % _sz;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;
        return _v[_head];
    }

    int getRear() {
        if (isEmpty())
            return -1;
        return _v[(_tail - 1 + _sz) % _sz];
    }

    bool isEmpty() {
        return _head == _tail;
    }

    bool isFull() {
        return (_tail + 1) % _sz == _head;
    }
private:
    int _head;
    int _tail;
    int _sz;
    vector<int> _v;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */