class Solution {
public:
    bool CanMakeSquare(vector<int>& matchsticks, int n, int index)
    {
        if (n == 0)
        {
            count--;
            if (count == 0)
                return true;
            if (CanMakeSquare(matchsticks, edge, matchsticks.size() - 1) == false)
            {
                count++;
                return false;
            }
            return true;
        }
        if (index < 0)
            return false;
        while (index >= 0)
        {
            if (matchsticks[index] == 0 || matchsticks[index] > n)
            {
                index--;
                continue;
            }
            int ret = matchsticks[index];
            matchsticks[index] = 0;
            if (CanMakeSquare(matchsticks, n - ret, index - 1))
            {
                return true;
            }
            matchsticks[index] = ret;
            index--;
        }
        return false;
    }

    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        std::sort(matchsticks.begin(), matchsticks.end());
        for (int& e : matchsticks)
        {
            sum += e;
        }
        edge = sum / 4;
        if (sum % 4 || matchsticks.size() < 4 || matchsticks[matchsticks.size() - 1] > edge)
            return false;
        if (CanMakeSquare(matchsticks, edge, matchsticks.size() - 1) == false)
            return false;
        sum = 0;
        for (int& e : matchsticks)
        {
            sum += e;
        }
        return sum == 0;
    }
private:
    int count = 4;
    int edge;
};