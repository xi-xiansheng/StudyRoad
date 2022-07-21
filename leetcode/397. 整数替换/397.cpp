/*class Solution {
public:
    int integerReplacement(int _n) {
        long long n = _n;
        int step = 0;
        while(n != 1)
        {
            if(n % 2 == 0)
                n /= 2;
            else
            {
                if(n != 3 && ((n >> 1) & 1 == 1))
                    n++;
                else
                    n--;
            }
            step++;
        }
        return step;
    }
};*/
class Solution {
public:
    int dfs(long long n)
    {
        if (n == 1)
            return 0;
        if (m.count(n))
            return  m[n];
        int ans = n % 2 == 0 ? dfs(n / 2) : std::min(dfs(n + 1), dfs(n - 1));
        m[n] = ans + 1;
        return ans + 1;
    }
    int integerReplacement(int n) {
        return dfs((long long)n);
    }
private:
    unordered_map<long long, int> m;
};