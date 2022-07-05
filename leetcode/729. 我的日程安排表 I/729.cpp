class MyCalendar {
public:
    MyCalendar() {
        s.clear();
    }

    bool book(int start, int end) {
        std::multiset<int>::iterator prev = s.begin();
        std::multiset<int>::iterator rear = s.begin();
        --end;
        if (prev != s.end())
            ++prev;
        while (prev != s.end())
        {
            if (!(start > *prev || end < *rear))
                return false;
            ++prev;
            rear = prev;
            if (prev != s.end())
                ++prev;
        }
        s.insert(start);
        s.insert(end);
        return true;
    }
private:
    multiset<int> s;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */