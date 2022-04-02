class Solution {
public:
    int reverse(int x) {
        int flag = 1;
        if (x < 0)
        {
            flag = -1;
            //x = -x;
        }
        long y = 0;
        while (x)
        {
            y = y * 10 + (x % 10);
            if ((y > 0 && y > 0x7fffffff) || (y < 0 && y < int(0x80000000)))
                return 0;
            x /= 10;
        }
        return int(y);
    }
};