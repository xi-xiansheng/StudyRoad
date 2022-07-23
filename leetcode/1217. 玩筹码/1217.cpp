class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        int a = 0, b = 0;
        for (int& e : position)
        {
            if (e % 2)
                a++;
            else
                b++;
        }
        return a < b ? a : b;
    }
};