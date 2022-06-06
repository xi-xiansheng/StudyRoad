class MyCalendarThree {
public:
    // ²î·ÖÊı×é
    MyCalendarThree() {
        m[-1] = 0;
    }
    int book(int start, int end) {
        m[start] += 1;
        m[end] -= 1;
        int ans = m[-1];
        int res = 0;
        std::map<int, int>::iterator it = m.begin();
        std::map<int, int>::iterator ot = m.begin();
        ot++;
        if (ot == m.end())
            cout << "---------";
        while (ot != m.end())
        {
            res = res + ot->second;
            ans = ans > res ? ans : res;
            it = ot;
            ++ot;
        }
        return ans;
    }

private:
    map<int, int> m;
    /*int book(int start, int end) {
        if(end > v.size())
        {
            v.resize(end);
        }
        for(int i = start; i < end; i++)
        {
            v[i] += 1;
            if(v[i] > ans)
                ans = v[i];
        }
        return ans;
    }
private:
    vector<int> v;
    int ans = 0;*/
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */