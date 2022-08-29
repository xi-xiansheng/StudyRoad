class Solution {
public:
    int calZero(long long n)
    {
        int ans = 0;
        while (n != 0)
        {
            n = n / 5;
            ans += n;
        }
        return ans;
    }

    int preimageSizeFZF(int k) {
        long long left = 4 * (long long)k, right = 5 * (long long)k + 1;
        while (left <= right)
        {
            long long mid = (left + right) / 2;
            int ret = calZero(mid);
            if (ret == k)    return 5;
            else if (ret > k)    right = mid - 1;
            else    left = mid + 1;
        }
        return 0;
    }
};