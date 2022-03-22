class Solution {
public:
    int LastRemaining_Solution(int n, int m) {
        //利用约瑟夫问题的递推公式 f(n,m) = ( f(n-1,m) +m)%n )
        int i = 2;
        int fn = 0;
        while (i <= n)
        {
            fn = (fn + m) % i;
            i++;
        }
        return fn;
    }
};