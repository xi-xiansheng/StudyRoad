class RecentCounter {
public:
    RecentCounter() {
        while (!q.empty())
        {
            q.pop();
        }
    }

    int ping(int t) {
        q.push(t);
        while (t - q.front() > 3000)
        {
            q.pop();
        }
        return q.size();
    }
private:
    queue<int> q;
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */