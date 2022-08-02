class MyCircularQueue {
private:
    vector<int> v;
    int prev = 0;
    int tail = 0;
    int sz = 0;
public:
    MyCircularQueue(int k) {
        v.resize(k + 1);
        sz = k + 1;
    }

    bool enQueue(int value) {
        if (isFull())
            return false;
        v[tail] = value;
        tail = (tail + 1) % sz;
        return true;
    }

    bool deQueue() {
        if (isEmpty())
            return false;
        prev = (prev + 1) % sz;
        return true;
    }

    int Front() {
        if (isEmpty())
            return -1;
        return v[prev];
    }

    int Rear() {
        if (isEmpty())
            return -1;
        return v[(tail + sz - 1) % sz];
    }

    bool isEmpty() {
        return prev == tail;
    }

    bool isFull() {
        return (tail + 1) % sz == prev;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */