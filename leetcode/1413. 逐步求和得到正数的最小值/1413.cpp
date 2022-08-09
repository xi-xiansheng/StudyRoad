class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min = 1;
        int sum = 1;
        for (auto& e : nums)
        {
            sum += e;
            if (sum < 1)
            {
                min += 1 - sum;
                sum = 1;
            }
        }
        return min;
    }
};