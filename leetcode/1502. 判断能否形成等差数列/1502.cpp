class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int sz = arr.size();
        int dif = arr[1] - arr[0];
        for (int i = 2; i < sz; i++)
        {
            if (arr[i] - arr[i - 1] != dif)
                return false;
        }
        return true;
    }
};