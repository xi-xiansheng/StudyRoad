class Solution {
public:
    /*int climbStairs(int n) {
        //ÇàÍÜÌøÌ¨½×--µÝ¹é
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        return climbStairs(n - 1) + climbStairs(n - 2);
    }*/
    int climbStairs(int n) {
        //ÇàÍÜÌøÌ¨½×--Ñ­»·
        int prev = 1;
        int next = 1;
        int result = 1;
        while (n - 1 > 0)
        {
            result = next + prev;
            prev = next;
            next = result;
            n--;
        }
        return result;
    }
};