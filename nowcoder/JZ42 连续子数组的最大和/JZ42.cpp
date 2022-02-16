class Solution {
public:
    int FindGreatestSumOfSubArray(vector<int> array) {
        int sum = array[0];
        int cur = 0;
        for (size_t i = 0; i < array.size(); i++)
        {
            if (cur < 0)
                cur = 0;
            cur += array[i];
            if (sum < cur)
                sum = cur;
        }
        return sum;
    }
};