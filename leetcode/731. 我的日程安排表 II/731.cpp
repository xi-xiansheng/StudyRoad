class MyCalendarTwo {
public:
    MyCalendarTwo() {
    }

    bool book(int start, int end) {
        m[start] += 1;
        m[end] -= 1;
        int res = 0;
        std::map<int, int>::iterator cur = m.begin();
        while (cur != m.end())
        {
            res = res + cur->second;
            if (res > 2)
            {
                m[start] -= 1;
                m[end] += 1;
                return false;
            }
            cur++;
        }
        return true;
    }
private:
    map<int, int> m;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */