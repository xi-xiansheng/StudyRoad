class Solution {
public:
    Solution(int n, vector<int>& blacklist) {
        count = n - blacklist.size();
        unordered_set<int> black;
        int bound = n - blacklist.size();
        for (int& e : blacklist)
        {
            if (e >= bound)
                black.insert(e);
        }
        int w = bound;
        for (int& e : blacklist)
        {
            if (e < bound)
            {
                while (black.count(w))
                {
                    w++;
                }
                BlackList[e] = w++;
            }
        }
    }

    int pick() {
        int index = rand() % count;
        return BlackList.count(index) ? BlackList[index] : index;
    }
private:
    unordered_map<int, int> BlackList;
    int count;
};